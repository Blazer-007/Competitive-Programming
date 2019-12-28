// Vivek Rai
// Blazer_007
// https://codeforces.com/contest/1283/problem/B
#include <bits/stdc++.h>
#define fastio 		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp(i,j)     make_pair(i,j)
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define loop(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

void solution(){
	ll n,k;
	cin>>n>>k;
	ll ans = (n/k)*k;
	ll rem = n%k;
	if(rem>(k/2)){
		ans = ans + (k/2) ;
	}else{
		ans = n;
	}
	cout<<ans<<endl;
}

signed main(){
    fastio;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
    	//cout<<"Case #"<<i<<":";
    	solution();
	} 
    return 0;
}       

