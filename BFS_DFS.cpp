#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int> > m;

public:
    
    void addEdge(int u,int v,int bid=false){
        m[u].push_back(v);
        if(bid){
            m[v].push_back(u);
        }
    }
    void show(){
        for(auto i:m){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    void dfsHelper(int node,map<int,bool> &visit){
        cout<<node<<"->";
        visit[node]=true;
        for(auto neighbour:m[node]){
            if(!visit[neighbour]){
                dfsHelper(neighbour,visit);
            }
        }
    }

    void dfs(int src){
        map<int,bool> visit;
        dfsHelper(src,visit);
    }

    void bfs(int src){
        queue<int> q;
        map<int,bool> visit;
        visit[src]=true;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto neighbour:m[node]){
                if(!visit[neighbour]){
                    q.push(neighbour);
                    visit[neighbour]=true;
                } 
            }
        }
    }

};

signed main() {
    int e,u,v;
    cin>>e;
    Graph g;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        g.addEdge(u,v,true);
    }
    g.bfs(1);
    return 0;
}
