// Vivek Rai
// Blazer_007
// https://www.spoj.com/problems/PT07Z/
#include<bits/stdc++.h> 
#define ll long long int 
#define pb push_back
const int N = 1e5+5;
using namespace std;

ll n;
std::vector<vector<ll> > adjList(N);
ll max_depth[N];
ll ans = 0 ;
void dfs(ll i,ll par){
    
    priority_queue <ll> pq;
    
    ll mx = 0;
    
    for(auto it: adjList[i]){
        if(it != par){
            dfs(it,i);
            pq.push(max_depth[it]+1);
            mx = max(mx,max_depth[it]+1);
        }
    }
    max_depth[i] = mx;
    ll dia = 0;
    if(pq.size())
        dia += pq.top(),pq.pop();
      
    if(pq.size())
        dia += pq.top(),pq.pop();
        
    ans = max(ans,dia);
}

signed main() 
{ 
    cin>>n;
    for(ll i=1;i<=n-1;i++){
        ll a,b;
        cin>>a>>b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    dfs(1,0);
    cout<<ans<<endl;
    
	return 0; 
} 
 

