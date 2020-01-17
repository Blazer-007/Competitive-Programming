/*

    Topological Sort  :- 1) Simple Algorithm that outputs linear ordering of vertices of the graph 
                            such that for every (u->v) u comes before v in the ordering.
                         2) Can be done using slightly modified both BFS and DFS.
                         3) Works only on DAG's : Directed Acyclic Graphs



*/

#include <bits/stdc++.h>
using namespace std;


template<typename T>
class Graph{

    map<T,list<T> > adjList;

public:
    Graph(){
        
    }

    // Bidirectional means if 0->1 edge is present then 1->0 edge should also be there
    void addEdge(T u,T v,bool bidir=false){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto row : adjList){
            cout<<row.first<<"->";
            for(T element:row.second){
                cout<<element<<",";
            }
            cout<<endl;
        }
    }

    void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering){

        visited[node] = true;

        // Will call dfs on unvisited node of current node
        for(T neighbour:adjList[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,ordering);
            }
        }

        // Add 1 line for TS 
        // At this point the children of current node would have been visited
        // So We can add current node to this list
        ordering.push_front(node);

    }

    void dfsTopologicalSort(){
        map<T,bool> visited;
        list<T> ordering;

        for(auto i:adjList){
            // i is pair (node, list of nodes)
            T node = i.first;
            if(!visited[node]){
                dfsHelper(node,visited,ordering);
            }
        }

        // Print all elements in ordering
        for(T element:ordering){
            cout<<element<<"->";
        }

    }


};

int main() {

    Graph<string> g;
    g.addEdge("English","Programming Logic");
    g.addEdge("Maths","Programming Logic");
    g.addEdge("Programming Logic","HTML");
    g.addEdge("Programming Logic","Python");
    g.addEdge("Programming Logic","Java");
    g.addEdge("Programming Logic","JS");
    g.addEdge("Python","Web Dev");
    g.addEdge("HTML","CSS");
    g.addEdge("CSS","JS");
    g.addEdge("JS","Web Dev");
    g.addEdge("Java","Web Dev");
    g.addEdge("Python","Web Dev");

    g.dfsTopologicalSort();

}

