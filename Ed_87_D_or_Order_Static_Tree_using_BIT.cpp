// Order Static Tree using Fenwick Tree
// https://codeforces.com/contest/1354/problem/D
// https://www.geeksforgeeks.org/order-statistic-tree-using-fenwick-tree-bit/

#include<bits/stdc++.h>
using namespace std;

const int MAXX = 1000010;
int BIT[MAXX] = {0};

/* Updates element at index 'i' of BIT. */
void update(int i, int add) { 
    while (i > 0 && i < MAXX) { 
        BIT[i] += add; 
        i = i + (i & (-i)); 
    } 
} 
  
/* Returns cumulative sum of all elements of 
   fenwick tree/BIT from start upto and 
   including element at index 'i'. */
int sum(int i) 
{ 
    int ans = 0; 
    while (i > 0) 
    { 
        ans += BIT[i]; 
        i = i - (i & (-i)); 
    } 
  
    return ans; 
} 
  
// Returns lower bound for k in BIT. 
int findKthSmallest(int k) { 
    // Do binary search in BIT[] for given 
    // value k. 
    int l = 0; 
    int h = MAXX; 
    while (l < h) { 
        int mid = (l + h) / 2; 
        if (k <= sum(mid)) 
            h = mid; 
        else
            l = mid+1; 
    } 
    return l; 
} 
  
// Insert x into BIT. We basically increment 
// rank of all elements greater than x. 
void insertElement(int x) { 
    update(x, 1); 
} 
  
// Delete x from BIT. We basically decreases 
// rank of all elements greater than x. 
void deleteElement(int x) { 
    update(x, -1); 
} 
  
// Returns rank of element. We basically 
// return sum of elements from start to 
// index x. 
int findRank(int x) { 
    return sum(x); 
}


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r" , stdin);
    	freopen("output.txt", "w", stdout);
    #endif

	int n , q;
	cin >> n >> q;

	int val;
	for(int i=0;i<n;i++){
		cin >> val;
		insertElement(val);
	}
	while(q--){
		int k;
		cin >> k;
		if(k<0){
			int vall = findKthSmallest(abs(k));
			deleteElement(vall);
		}else{
			if(k>=1 && k<=n)
				insertElement(k);
		}
	}
	if(sum(n)>0)
		cout << findKthSmallest(1) << endl;
	else
		cout << 0 << endl;
}