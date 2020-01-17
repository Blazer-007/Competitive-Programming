/*

    Topological Sort  :- 1) Simple Algorithm that outputs linear ordering of vertices of the graph 
                            such that for every (u->v) u comes before v in the ordering.
                         2) Can be done using slightly modified both BFS and DFS.
                         3) Works only on DAG's : Directed Acyclic Graphs
                         
    Using BFS :- 1) A Queue and Array/Map for storing indegree of every node
    			 2) Algorithm starts from finding vertices with zero indegree
    			 3) Enqueue all vertices with zero indegree into a queue
    			 



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


    void TopologicalSort(){
//    	cout<<"1\n";
    	queue<T> q;
        map<T,bool> visited;
        map<T,int> indegree;
        
        for(auto i:adjList){
        	// i is pair of node and its list
        	T node = i.first;
        	visited[node] = false;
        	indegree[node] = 0;
		}
//		cout<<"2\n";
		
		// Init the indegrees of all node
		for(auto i:adjList){
			T u = i.first;
			for(T v:adjList[u]){
				indegree[v]++;
			}
		}
//		cout<<"3\n";
		
		// Find out all the nodes with zero indegrees
		for(auto i:adjList){
			T node = i.first;
			if(indegree[node]==0){
				q.push(node);
			}
		}
//		cout<<"4\n";
		
		// Start with Algorithm
		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<"-->";
			
			for(T neighbour:adjList[node]){
				indegree[neighbour]--;
				
				if(indegree[neighbour]==0){
					q.push(neighbour);
				}
			}
		}
//		cout<<"5\n";
        

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

    g.TopologicalSort();

}

