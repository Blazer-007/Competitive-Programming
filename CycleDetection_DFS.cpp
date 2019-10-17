/* Cycle Detection using DFS is used for directed graphs

	Back Edge :- It is a edge such that from a vertex state"currently in stack" to a vertex 
				 with state"currently in stack"(Ancestor) in DFS traversal is called back-edge.
				 
				 If u->v is an back-edge then u comes in the path of v or u is an ancestor of v.
				 
				 "Currently in Stack" means the current node has been visited but not completed 
				 hence present in DFS call stack;

	Here we will try to find is there any back-edge is present or not .
	No of cycles = No of back-edges
	
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
    
    bool isCyclicHelper(T node,map<T,bool> &visited,map<T,bool> &inStack){
    	
    	// Processing the current node - visited & inStack
    	visited[node] = true;
    	inStack[node] = true;
    	
    	// Explore the neighbours of node
    	for(T neighbour:adjList[node]){
    		// Two things can happen
    		// The current node is not visited but its further branch leads to a cycle
    		if(!visited[neighbour] && isCyclicHelper(neighbour,visited,inStack) || inStack[neighbour])
    		return true;
		}
		// Pop out the node , inStack = false
		inStack[node] = false;
		return false;
	}
    
	bool isCyclic(){
		map<T,bool> visited;
		map<T,bool> inStack;
		
		// To check for cycle in each dfs tree
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
			bool cyclePresent =	isCyclicHelper(node,visited,inStack);
			if(cyclePresent)
			return true;
			}
		}
		return false;
	}

};



int main() {
    Graph<int> g;

    g.addEdge(0,2,false);
    g.addEdge(0,1,false);
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
//    g.addEdge(3,0,false);
    g.addEdge(4,5,false);
    g.addEdge(1,5,false);
    
    if(g.isCyclic()){
    	cout<<"Cyclic Graph";
	}else{
		cout<<"Not Cyclic Graph";
	}
    
}

