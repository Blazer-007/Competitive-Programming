// Vivek Rai
// Blazer_007

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

#include <bits/stdc++.h>
#define fastio 		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp(i,j)     make_pair(i,j)
#define inf         0x3f3f3f3f
//#define INF         0x3f3f3f3f3f3f3f3fLL
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

#define INF 1000000007
 
ll f[100001];
 
ll pow(ll a, ll b, ll MOD)
{
 ll x=1,y=a; 
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y*y);
 	if(y>MOD) y%=MOD; 
 	b /= 2;
 	}
 return x;
}
 
/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n, ll MOD)
{
 return pow(n,MOD-2,MOD);
}
 
ll C(ll n, ll r, ll MOD)
{
 
 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}


void solution(){
	
}

signed main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    #endif
    fastio;
    f[0] = 1;
	for(int i = 1 ; i <= 100000 ; i++)
		f[i] = (f[i-1]*i)%INF;
//    clock_t time_req;
    //code to be written here
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
    	//cout<<"Case #"<<i<<":";
    	solution();
	}  
	
	
//	time_req = clock() - time_req;
//    cout<<endl<< "Processor time taken is "<< (double)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	     
    return 0;
}       

