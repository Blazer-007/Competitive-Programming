// Vivek Rai
// Blazer_007
/*

    Given a set of n integers, find the sum of xor of all subarray.

*/


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(vector<int>& arr,int n){
    ll sum = 0; 
    ll mul = 1; 
  
    for (int i = 0; i < 30; i++) { 
        int c_odd = 0; 
        bool odd = 0; 
        for (int j = 0; j < n; j++) { 
            if ((arr[j] & (1 << i)) > 0) 
                odd = (!odd); 
            if (odd) 
                c_odd++; 
        } 
        for (int j = 0; j < n; j++) { 
            sum += (mul * c_odd); 
  
            if ((arr[j] & (1 << i)) > 0) 
                c_odd = (n - j - c_odd); 
        } 
        mul *= 2; 
    } 
    return sum;
}

signed main () {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i] ;
	
	cout << solve(v,n) << '\n' ;

	return 0;
}