#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

class Edge{
	public:
		int src,dest,weight;
};

class Graph{
	public:
		int v,e;
		Edge *edge;
		Graph(int v,int e){
			this->v = v;
			this->e = e;
			edge = new Edge[e];
		}
		
		void addEdge(int u,int v,int w,int count){
			
//			cout<<"called->";
			
			edge[count].src = u;
			edge[count].dest = v;
			edge[count].weight = w;
		}
		
		void BellmanFord(int src){
//			cout<<"Bell->1";
			int distance[v];
			for(int i=0;i<v;i++){
				if(i==src){
					distance[i] = 0;
				}else{
					distance[i] = inf;
				}
			}
//			cout<<"Bell->2";
			// Relaxation Code
			for(int i=1;i<=v-1;i++){
//				cout<<i;
				for(int j=0;j<e;j++){
//					cout<<"->"<<j<<"s";
					int src = edge[j].src;
					int dest = edge[j].dest;
					int wt = edge[j].weight;
					
//					cout<<"->"<<j<<"m";
					
					// Relaxatation Check
					if(distance[src] !=inf and distance[src] + wt < distance[dest]){
						distance[dest] = distance[src] + wt;
					}
					
//					cout<<"->"<<j<<"e";
				}
//				cout<<endl;
			}
//			cout<<"Bell->3";
			
			// Checking for negative cycles
			for(int j=0;j<e;j++){
					int src = edge[j].src;
					int dest = edge[j].dest;
					int wt = edge[j].weight;
					
					// Relaxatation Check
					if(distance[src]!=inf and distance[src] + wt < distance[dest]){
						cout<<"Graph contains negative weight cycles \n";
						return;
					}
			}
//			cout<<"Bell->4";
			
			for(int i=0;i<v;i++){
				cout<<i<<" -> "<<distance[i]<<endl;
			}
//			cout<<"Bell->5";
			
			return;
			
		}
};

int main(){
	
	int v,e;
	cin>>v>>e;
	Graph g(v,e);
	for(int i=1;i<=e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w,i);
	}
//	cout<<endl;
	g.BellmanFord(0);
	
	return 0;
	
}







