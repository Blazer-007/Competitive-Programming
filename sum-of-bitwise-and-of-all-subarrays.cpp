// Vivek Rai
// Blazer_007
/*

    Given an array A1, A2 . . . AN , find the sum of bitwise AND of all the subarrays of A.

*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(vector<ll> arr, ll n) { 
	ll ans = 0; 
	ll mul = 1; 

	for (ll i = 0; i < 30; i++) { 
		bool count_on = 0;  
		ll l = 0; 
		for (ll j = 0; j < n; j++) { 
			if ((arr[j] & (1 << i)) > 0) 
				if (count_on) 
					l++; 
				else { 
					count_on = 1; 
					l++; 
				} 

			else if (count_on) { 
				ans += ((mul * l * (l + 1)) / 2); 
				count_on = 0; 
				l = 0; 
			} 
		} 
		if (count_on) { 
			ans += ((mul * l * (l + 1)) / 2); 
			count_on = 0; 
			l = 0; 
		}  
		mul *= 2; 
	} 

	return ans; 
} 

signed main () {
	int n;
	cin >> n;
	vector<ll> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i] ;
	
	cout << solve(v,n) << '\n' ;

	return 0;
}
