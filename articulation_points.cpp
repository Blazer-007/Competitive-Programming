// Vivek Rai
// Blazer_007

#include<bits/stdc++.h>
using namespace std;

#define fastio    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl      '\n'

typedef long long int ll;
const int hell = 1e9 + 7 ;

const int N = (int)1e5 + 5;
vector<int> graph[ N ];
vector<bool> visited( N , false );
vector<int> in( N , 0 ); // in[i] -> entry time of ith node
vector<int> low( N , 0); // low[i] -> lowest ancestor that can be reached from ith node
set<int> articulation_point;
int timer;

void dfs(int src, int par)
{
    visited[src] = true;
    in[src] = low[src] = timer;
    timer++;
    int children = 0;
    for(int node : graph[src])
    {
        if (node == par)
            continue;
        else if (visited[node] == true)
            low[src] = min(in[node], low[src]);
        else
        {
            dfs(node, src);

            if (low[node] >= in[src] and par != -1)
                articulation_point.insert(src);

            low[src] = min(low[src], low[node]);

            children++;
        }
    }

    if (par == -1 and children > 1)
        articulation_point.insert(src);
}

signed main()
{

    fastio
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 0 ; i < N ; i++)
    	visited[i] = false;

    timer = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i, -1);
    }

    cout << "No of Articulation Point are " << (int)articulation_point.size() << endl;
    cout << "Articulation Points are : ";
    for(auto it : articulation_point)
        cout << it << " , ";
    cout << endl;

    return 0;
}