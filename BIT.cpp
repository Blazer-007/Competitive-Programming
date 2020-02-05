// link to question
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-round-numbers/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int bt[200011];
ll A[200011];
int N;
int round(ll x){
	if(x<0) return 0;
	if(x==0) return 1;
	int p=x%10;
	int r;
	while(x>0){
		r=x%10;
		x/=10;
	}
	return ( p==r );
}
void update(int ind,int val){
	while(ind<=N){
		bt[ind]+=val;
		ind+=(ind&-ind);
	}
}
int query(int ind){
	int ans=0;
	while(ind>0){
		ans+=bt[ind];
		ind-=(ind&-ind);
	}
	return ans;
}
int main(){	
	
	int Q;
	cin >> N >> Q;
	for(int i=1;i<N+1;i++){
		cin >> A[i];
		update(i,round(A[i]));
	}
	ll t,l,r;
	while(Q--){
		cin >> t >> l >> r;
		if(t==2){
			update(l,-round(A[l]));
			A[l]=r;
			update(l,round(A[l]));
		}
		else{
			cout<<query(r)-query(l-1)<<"\n";
		}
	}
}
