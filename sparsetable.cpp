// Vivek Rai
// Blazer_007
// Range Query using Sparse Table
// Query Output in O(1) only for Idempotent functions i.e. A*A = A 

#include<bits/stdc++.h>
using namespace std;

#define fastio    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl      '\n'

typedef long long int ll;
const int hell = 1e9 + 7 ;

const int N = 1e6 + 6;
const int K = log2(N) + 1;
vector<vector<int> > sparseTable(N, vector<int>(K));
vector<int> arr( N );
int n;

void preprocess()
{
	for(int i = 0 ; i < n ; i++)
		sparseTable[i][0] = arr[i];

	for(int j = 1 ; (1 << j) < n ; j++)
	{
		for(int i = 0 ; i + (1 << j) - 1 < n ; i++)
		{
			// sparseTable[i][j] = sparseTable[i][j-1] & sparseTable[i + (1 << (j-1))][j-1];
			// sparseTable[i][j] = sparseTable[i][j-1] + sparseTable[i + (1 << (j-1))][j-1];
			sparseTable[i][j] = min(sparseTable[i][j-1], sparseTable[i + (1 << (j-1))][j-1]);
		}
	}
}

int query(int l, int r) // O(logn)
{
	// int ans = (1 << 30) - 1;
	int ans = 0;
	for (int j = K; j >= 0; j--) {
	    if ((1 << j) <= r - l + 1) {
	        ans &= sparseTable[l][j];
	        ans += sparseTable[l][j];
	        l += 1 << j;
	    }
	}
	return ans;
}

int query_range_min(int l, int r) // O(1)
{
	int j = log2(r - l + 1);
	// int ans = min(sparseTable[l][j], sparseTable[r - (1 << j) + 1][j]);
	int ans = sparseTable[l][j] & sparseTable[r - (1 << j) + 1][j];
	return ans;
}

int query_bruteForce(int l, int r)
{
	int ans = arr[l];
	for(int i = l+1 ; i <= r ; i++){
		ans &= arr[i];
		// ans += arr[i];
		// ans = min(ans, arr[i]);
	}
	return ans;
}

signed main() {

    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    	cin >> arr[i];

    preprocess();

    // cout << query(1,2) << " " << query_bruteForce(1,2) << endl;
    // cout << query(0,2) << " " << query_bruteForce(0,2) << endl;
    // cout << query(3,5) << " " << query_bruteForce(3,5) << endl;
    // cout << query(5,5) << " " << query_bruteForce(5,5) << endl;
    cout << query_range_min(1,2) << " " << query_bruteForce(1,2) << endl;
    cout << query_range_min(0,2) << " " << query_bruteForce(0,2) << endl;
    cout << query_range_min(3,5) << " " << query_bruteForce(3,5) << endl;
    cout << query_range_min(5,5) << " " << query_bruteForce(5,5) << endl;
    cout << query_range_min(0,14) << " " << query_bruteForce(0,14) << endl;

    return 0;
}