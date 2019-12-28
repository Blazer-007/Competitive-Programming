// Vivek Rai
// Blazer_007
// https://codeforces.com/contest/1283/problem/E
#include <bits/stdc++.h>
#define fastio 		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp(i,j)     make_pair(i,j)
#define ll          long long int
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
//#define loop(i,a,b)  for(ll i=a;i<b;i++)
using namespace std;

void solution(){
	ll n;
	cin>>n;
	ll arr[n+3]={0},ar[n+3]={0};
	set<ll> s;
	ll count=0,ans_min=0,ans_max=0;
	ll x;
	for(ll i=0;i<n;i++){
		cin>>x;
		arr[x]++;
		ar[x]++;
		s.insert(x);
	}
//	count = sz(s);
	ll i,j;
	// for min
	for(ll i=0;i<n+2;i++){
		if(arr[i]!=0){
					arr[i+1] = arr[i] + arr[i+2] ;
					arr[i] = 0;
					arr[i+2] = 0;
					i = i+2;
			}
	}
	for(j=0;j<n+2;j++){
		if(arr[j]!=0)ans_min++;
	}
	// for max
	for(ll i=1;i<n+2;i++){
		if(ar[i]>2){
			ar[i-1]++;
			if(ar[i+1]==0){
				ar[i+1]++;
				i = i+1 ;
			}
		}else if(ar[i]==2){
			if(ar[i-1]==0){
				ar[i-1]++;
			}else{
				if(ar[i+1]==0){
					ar[i+1]++;
					i = i+1 ;
				}	
			}
		}
	}
	for(ll i=0;i<n+2;i++){
		if(ar[i]!=0)ans_max++;
	}
//	ans_min = min(count,ans_min);
//	ans_max = max(count,ans_max);
	cout<<ans_min<<" "<<ans_max<<endl;
}

signed main(){
    fastio;
    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++){
    	//cout<<"Case #"<<i<<":";
    	solution();
	} 
    return 0;
}       

