// Vivek Rai
// Blazer_007
// Link - https://cses.fi/problemset/task/1139/
 
#include <bits/stdc++.h>
using namespace std;
 
#define pb          push_back
#define endl        '\n'
#define sz(x)       (int)x.size()
#define all(a)      begin(a), end(a)
#define fl(i, a, b) for (int i = a; i < b; i++)
#define rl(i, a, b) for (int i = a; i >= b; i--)
 
using ll  = long long int;
using vi  = vector<int>;
using vl  = vector<ll>;
using pi  = pair<int, int>;
using pl  = pair<ll, ll>;
using mi  = map<int, int>;
using ml  = map<ll, ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
 
const int hell = 1e9 + 7;
const int mod = 998244353;
const int maxN = 23;
const int N = 200001;
const int BLOCK_SIZE = 500;
 
template <typename T>
istream &operator>>(istream &in, vector<T> &arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
        cin >> arr[i];
    return in;
}
 
template <typename T>
ostream &operator<<(ostream &os, vector<T> arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
        cout << arr[i] << " ";
    cout << endl;
    return os;
}
 
int n;
vector<int> tree[ N ], ans( N, 0 ), color( N );
set<int> *s[ N ];
 
void dfs(int src, int par)
{
    int maxx = 0, maxNode = -1;
    for (auto node : tree[src])
    {
        if (node != par)
        {
            dfs(node, src);
            if (s[node]->size() > maxx)
            {
                maxx = s[node]->size();
                maxNode = node;
            }
        }
    }
    if (maxNode == -1)
        s[src] = new set<int>();
    else
        s[src] = s[maxNode];
    s[src]->insert(color[src]);
    for (auto node : tree[src])
    {
        if (node != par && node != maxNode)
        {
            for (auto col : *s[node])
                s[src]->insert(col);
        }
    }
    ans[src] = s[src]->size();
}
 
void solve()
{
    cin >> n;
    fl(i,1,n+1)
        cin >> color[i];
    fl(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1,0);
    fl(i,1,n+1)
        cout << ans[i] << ' ';
    
}
 
signed main()
{
 
#ifndef ONLINE_JUDGE
    freopen("F:/Code/input.txt", "r", stdin);
    freopen("F:/Code/output.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
 
    return 0;
}