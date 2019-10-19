// Vivek Rai
// Blazer_007

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

ll togglebit(ll n) 
{ 
    if (n == 0) 
        return 1; 
    ll i = n;  
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    return i ^ n; 
} 
  
ll XNOR(ll num1, ll num2) 
{  
    if (num1 < num2) 
        swap(num1, num2);  
    num1 = togglebit(num1); 
    
    return num1 ^ num2; 
} 

void solution(){
	ll a,b;
	cin>>a>>b;
	cout<<"XNOR of given numbers are "<<XNOR(a,b)<<endl;
}

signed main(){
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    #endif
    fastio;
    //code to be written here
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
    	//cout<<"Case #"<<i<<":";
    	solution();
	}       
    return 0;
}       

