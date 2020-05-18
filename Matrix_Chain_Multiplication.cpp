// Vivek Rai
// Blazer_007

#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > dp(100,vector<int>(100,-1));

int matrixChain(vector<int>& m,int i, int j){
	if(i == j){
		dp[i][j] = 0;
		return 0;
	}

	if(dp[i][j] != -1)
		return dp[i][j] ;

	int ans = INT_MAX;

	for(int k = i; k < j; k++){
		int temp = matrixChain(m,i,k) + matrixChain(m,k+1,j) + m[i-1]*m[k]*m[j] ;
		ans = min(ans,temp) ;
	}

	return dp[i][j] = ans;
}

signed main(){
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r" , stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i] ; // size of matrix i = arr[i-1]*arr[i]
	
	cout << matrixChain(arr,1,n-1) << endl;
    
}


