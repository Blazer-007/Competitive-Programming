// Vivek Rai
// Blazer_007
/*

    Given an array A1, A2 . . . AN , find the sum of bitwise OR of all the subarrays of A.

*/

#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

ll solve(vector<ll> arr, ll n) { 
	ll maxx = *max_element(arr.begin(),arr.end()); 
	ll maxBit = log2(maxx) + 1; 
	ll totalSubarrays = n * (n + 1) / 2; 
	ll ans = 0; 
	for (ll i = 0; i < maxBit; i++) { 
		ll c1 = 0; 
		vector<ll> vec; 
		ll sum = 0; 
		for (ll j = 0; j < n; j++) { 
			ll a = arr[j] >> i; 
			if (!(a & 1)) { 
				vec.push_back(j); 
			} 
		} 
		ll cntSubarrNotSet = 0;
		ll cnt = 1; 
		for (ll j = 1; j < vec.size(); j++) { 
			if (vec[j] - vec[j - 1] == 1) { 
				cnt++; 
			} 
			else { 
				cntSubarrNotSet += cnt * (cnt + 1) / 2; 
				cnt = 1; 
			} 
		} 
		cntSubarrNotSet += cnt * (cnt + 1) / 2;
		if (vec.size() == 0) 
			cntSubarrNotSet = 0; 
		ll cntSubarrIthSet = totalSubarrays - cntSubarrNotSet; 

		ans += cntSubarrIthSet * pow(2, i); 
	} 
	return ans; 
} 

signed main() 
{ 
	int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i] ;

	cout << solve(arr, n) << '\n'; 

	return 0; 
} 

