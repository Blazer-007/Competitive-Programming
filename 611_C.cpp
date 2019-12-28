// Vivek Rai
// Blazer_007
// https://codeforces.com/contest/1283/problem/C
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
	ll n,x;
	cin>>n;
	ll count[n+1]={0};
//	memset(count,0,n+3);
	vector<ll> v,v1;
	loop(i,1,n+1){
		cin>>x;
		v.pb(x);
		count[x]=1;
	}
	loop(j,1,n+3){
		if(count[j]==0)v1.pb(j);
	}
	sort(all(v1));
	
	loop(i,0,sz(v1)){
		cout<<v1[i]<<" ";
	}cout<<endl;
	
	vector<ll>::iterator it;
	ll idx=0;
	loop(i,0,n){
		if(v[i]==0){
			
			if((v1[idx]!=(i+1))&&v1[idx]!=-1){
				v[i] = v1[idx];
				it = v1.begin() ;
				it += (idx) ;
				v1.erase(it);
				idx++;
			}else{
				v[i]=v1[idx+1];
				v1[idx+1]=-1;
				it = v1.begin() ;
				it += (idx+1) ;
				v1.erase(it);
			}
		}
	}
	loop(i,0,n){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
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

