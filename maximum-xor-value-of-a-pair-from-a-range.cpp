// Vivek Rai
// Blazer_007
/*

    Given two integers l and r , your task is to find the maximum xor of two integers both of which lying between l and r inclusive.

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll solve(ll l,ll r){
	ll res = l ^ r ;

	int msbPos = 0;
	while(res){
		msbPos++;
		res >>= 1;
	}
		

	ll ans = 0;
	ll val = 1;
	while(msbPos){
		ans += val;
		val <<= 1;
		msbPos--;
	}

	return ans;
}

signed main () {
	ll L,R;
	cin >> L >> R;
	cout << solve(L,R) << '\n';
}