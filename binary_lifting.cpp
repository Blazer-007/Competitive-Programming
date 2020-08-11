// Vivek Rai
// Blazer_007

#include<bits/stdc++.h>
using namespace std;

#define fastio    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl      '\n'

typedef long long int ll;
const int hell = 1e9 + 7 ;

const int N = 1000;
const int maxN = 10;

int n;
vector<int> tree[ N ];
vector<int> level( N );
vector<vector<int> > LCA(N, vector<int>(maxN + 1, -1));

void dfs(int src, int par, int lvl)
{
	LCA[src][0] = par;
	level[src]  = lvl;
	for(int child : tree[src])
	{
		if (child != par)
			dfs(child, src, lvl + 1);
	}
}

void binary_lifting()
{
	dfs(1, -1, 0);

	for(int j = 1 ; j <= maxN ; j++)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			if (LCA[i][j-1] != -1)
			{
				int par = LCA[i][j-1];
				LCA[i][j] = LCA[par][j-1];
			}
		}
	}
}

int getLCA(int a, int b)
{
	if (level[b] < level[a])
		swap(a,b);

	int d = level[b] - level[a];

	while(d > 0)
	{
		int i = log2(d);
		b = LCA[b][i];

		d -= (1 << i);
	}

	if (a == b)
		return a;

	for(int j = maxN ; j >= 0 ; j--)
	{
		if (LCA[a][j] != -1 and (LCA[a][j] != LCA[b][j]))
		{
			a = LCA[a][j];
			b = LCA[b][j];
		}
	}

	return LCA[a][0];
}

int calcDist(int a, int b)
{
	int lca = getLCA(a , b);
	return level[a] + level[b] - 2*level[lca];
}

signed main() {

    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif

    
    cin >> n;

    for(int i = 1 ; i < n ; i++)
    {
    	int u,v;
    	cin >> u >> v;
    	tree[u].push_back(v);
    	tree[v].push_back(u);
    }

    binary_lifting();

    int q;
    cin >> q;
    while(q--)
    {
    	int a, b;
    	cin >> a >> b;
    	cout << "LCA of " << a << " and " << b << " : " << getLCA(a,b) << endl;
    	cout << "Distance between " << a << " and " << b << " : " << calcDist(a,b) << endl;
    }

    return 0;
}