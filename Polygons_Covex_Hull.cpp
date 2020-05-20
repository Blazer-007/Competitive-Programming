// Vivek Rai
// Blazer_007
// https://codeforces.com/problemset/problem/166/B

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>

#define fastio 		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define inf         0x3f3f3f3f
//#define INF         0x3f3f3f3f3f3f3f3fLL
#define ll          long long
#define int 		ll
#define pb          push_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define ppi	    	pair<ll,pii>
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define see(x)	    cout<<x<<endl;
#define see2(x,y)   cout<<x<<" "<<y<<endl;
#define see3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define bit(x, y)   (((x)>>(y))&1)
#define bpt(x)      (__builtin_popcount(x))
#define bptl(x)     (__builtin_popcountll(x))
#define loop(i,a,b)  for(int i=a;i<b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)
#define N 2000010

using namespace std;
//using namespace __gnu_pbds;

//typedef priority_queue<int> maxHeap;
//typedef priority_queue<int,vector<int>,greater<int>()) minHeap;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(index) -> value at given index or Kth smallest element in set
// order_of_key(X) -> number of elements strictly less than X
//typedef tree<pii , null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

struct point {
	int x, y;
	bool operator < (point &O) {
		if (O.x == x) return y < O.y;
		else return x < O.x;
	}
	bool operator == (point &O) {
		return (x == O.x && y == O.y);
	}
};
 
bool cw(point a, point b, point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
 
bool ccw(point a, point b, point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
 
bool collinear(point a, point b, point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0;
}
 
void convex_hull(vector<point> &p) {
	if (p.size() <= 2) return;
 
	sort(p.begin(), p.end());
	// now p[0] is p1, p[n-1] is p2
	int i, n = p.size();
	point p1 = p[0], p2 = p[n - 1];
	// actually p1 is bottom left point and p2 is top right point
	vector<point> up, down;
	up.pb(p1);
	down.pb(p1);
 
	for (i = 1; i < n; i++) {
		// now i have to check whether my current point is in lower half
		// or upper half
		if (i == n - 1 || !ccw(p1, p[i], p2)) {
			// p[i] is in the upper half
			while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i])) {
				up.pop_back();
			}
			up.pb(p[i]);
		}
		if (i == n - 1 || !cw(p1, p[i], p2)) {
			// p[i] is in the lower half
			while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i])) {
				down.pop_back();
			}
			down.pb(p[i]);
		}
	}
	// up and down vector contains all points including the points p1 and p2 repeatedly
	p.clear();
	for (i = 0; i < up.size(); i++) {
		p.pb(up[i]);
	}
	for (i = 0; i < down.size(); i++) {
		p.pb(down[i]);
	}
	// p vector contais all the pints from up as well as down
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
}
 
void solution() {
	int i, j, n, m;
	cin >> n;
	vector<point> p(n);
	for (i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	map<pair<int, int>, int> mp;
	cin >> m;
	for (i = 0; i < m; i++) {
		point temp;
		cin >> temp.x >> temp.y;
		mp[ {temp.x, temp.y}]++;
		p.pb(temp);
	}
	convex_hull(p);
	// now p contains all the points of convex hull
	for (auto x : p) {
		// cout << x.x << " " << x.y << '\n';
		if (mp.count({x.x, x.y})) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
	return;
 
}

signed main(){
    fastio
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r" , stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    ll t=1;
    // cin>>t;
    loop(i,1,t+1){
    	//cout<<"Case #"<<i<<": ";
    	solution();
    }
}


