//  Cycle detection using BFS is used for Undirected Graph

/*
 	BFS for graph :- Here we choose a source node and push into a empty queue and mark it visited 
 					 Now we will run a loop while queue is not empty and pop the front element of
 					 queue  , print it and push its adjacent node if not pushed earlier .
					  
	DFS for graph :- Here we choose a node and mark it visited and then iterate recursively over 
					 the adjacent node which is not visited. 
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
    void addEdge(T u,T v,bool bidir=true){
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
    
	bool isCyclicBFS(T src){
		map<T,bool> visited;
		map<T,int>  parent;
		queue<T>    q;
		
		visited[src]=true;
		parent[src]=src;
		q.push(src);
		
		while(!q.empty()){
			T node = q.front();
			q.pop();
			
			for(T neighbour:adjList[node]){
				if(visited[neighbour]==true && parent[node]!=neighbour){
					return true;
				}else if(!visited[neighbour]){
					visited[neighbour] = true;
					parent[neighbour] = node;
					q.push(neighbour);
				}
			}
		}
		return false;
	}

};



int main() {
    Graph<int> g;

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
//    g.addEdge(4,1);
    
    if(g.isCyclicBFS(1)){
    	cout<<"Cyclic Graph";
	}else{
		cout<<"Not Cyclic Graph";
	}
    
}

