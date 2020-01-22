#include<bits/stdc++.h> 
#define ll long long int 
#define pb push_back
const int N = 200010;
using namespace std;

ll ans = 0,n;
vector < vector < ll > > adjlist ( N );
ll W[ N ], P[ N ];
ll ma[ N ], mi[ N ];
void dfs ( ll i, ll par ){
    for ( auto it : adjlist[i] ){
        if ( it != par ){
            dfs(it,i);
            ma[i] = max(ma[i],ma[it]);
            mi[i] = min(mi[i],mi[it]);
        }
    }
    ma[i] = max(ma[i],W[i]);
    mi[i] = min(mi[i],W[i]);
    ans = max(ans,abs(W[i]-ma[i]));
    ans = max(ans,abs(W[i]-mi[i]));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin >> n ;
    for ( ll i = 1; i <= n; i ++){
        ma[i] = INT_MIN;
        mi[i] = INT_MAX;
    }
    ll root = 0;
    for ( ll i = 1; i <= n; i ++){
        cin >> W[i];
    }
    for ( ll i = 1; i <= n; i ++){
        cin >> P[i];
        if ( P[i] == -1 ){
            root = i;
        }
        else{
            adjlist[P[i]].pb(i);
        }
    }
    dfs(root,0);
    cout << ans;

}
