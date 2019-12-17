/*
		Rod Cutting Problem :- find maximum profit that can be obtained from 
								a rod of given length and price of each length 
								from 1 to length of rod.
*/



#include <bits/stdc++.h>
using namespace std;

int memo[100];

int maxProfit(int arr[],int totalLen){
	if(totalLen == 0) return 0;
	
	if(memo[totalLen] != -1){
		return memo[totalLen];
	}
	
	int best =0;
	for(int len = 1;len<=totalLen;++len){
		int netProfit = arr[len] + maxProfit(arr, totalLen-len);
		best = max(best, netProfit);
	}
	
	memo[totalLen] = best;
	return best;
}

// DP - Bottom Up Approach
int maxProfit_DP(int arr[],int totalLen){
	int dp[100] = {0};
	
	for(int len = 1;len<=totalLen;++len){
		int best = 0;
		for(int cut = 1;cut<=len;++cut){
			best = max(best,arr[cut]+dp[len-cut]);
		}
		dp[len]=best;
	}
	
	return dp[totalLen];
}


signed main(){
	int priceOfEachLen[100];
	int totalLen;
	cin>>totalLen;
	
	for(int eachPiece = 1;eachPiece <= totalLen; ++eachPiece){
		cin>> priceOfEachLen[eachPiece];
	}
	
	for(int i=0;i<=totalLen;i++){
		memo[i] = -1;
	}
	
	int ans = maxProfit(priceOfEachLen, totalLen);
	cout<<ans;
	
	
	return 0;
}
