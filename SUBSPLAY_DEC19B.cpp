// Vivek Rai
// Blazer_007
// https://www.codechef.com/DEC19B/problems/SUBSPLAY
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

#include <bits/stdc++.h>
#define fastio 		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp(i,j)     make_pair(i,j)
#define inf         0x3f3f3f3f
#define INF         0x3f3f3f3f3f3f3f3fLL
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
#define bit(x, y)   (((x)>>(y))&1)
#define bctz(x)     (__builtin_ctz(x))
#define bclz(x)     (__builtin_clz(x))
#define bclzl(x)    (__builtin_clzll(x))
#define bctzl(x)    (__builtin_ctzll(x))
#define bpt(x)      (__builtin_popcount(x))
#define bptl(x)     (__builtin_popcountll(x))
#define loop(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

const int maxx = 1e5+5;
void solution(){
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll last[26];
	ll ans[26];
	memset(last,-1,sizeof(last));
	loop(i,0,26){
		ans[i] = maxx;
	}
//	loop(i,0,26){
//		cout<<last[i]<<" "<<ans[i]<<endl;
//	}
	int flag = 0;
	loop(i,0,sz(s)){
	    int idx = s[i]-97;
	    if(last[idx]==-1){
	        last[idx] = i;
	    }else{
	        ll minn = i - last[idx] - 1 ;
	        if(minn<=ans[idx]){
	            ans[idx] = minn;
	        }
	        flag = 1 ;
	        last[idx] = i;
	    }
	}
	if(flag==0){
	    cout<<"0"<<endl;
	}else{
	    sort(ans,ans+26);
//	    loop(i,0,26){
//			cout<<last[i]<<" "<<ans[i]<<endl;
//		}
	    ll anss = sz(s) - ans[0] - 1 ;
	    cout<<anss<<endl;
	}
}

signed main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    #endif
    fastio;
//    clock_t time_req;
    //code to be written here
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    	//cout<<"Case #"<<i<<":";
    	solution();
	}  
	
	
//	time_req = clock() - time_req;
//    cout<<endl<< "Processor time taken is "<< (double)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	     
    return 0;
}       

