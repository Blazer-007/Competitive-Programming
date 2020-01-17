// It prints minimum spanning tree

#include<bits/stdc++.h>
using namespace std;

class Edge{
	public:
		int src;
		int dest;
		int weight;
};

class Set{
	public:
		int parent;
		int rank;
};

int find(Set *set,int i){
	if(set[i].parent != i){
		set[i].parent = find(set,set[i].parent);
	}
	return set[i].parent;
}

void Union(Set *set,int v1,int v2){
	int v1_root = find(set, v1);
	int v2_root = find(set, v2);
	if(set[v1_root].rank < set[v2_root].rank){
		set[v1_root].parent = v2_root;
	}
	else if(set[v1_root].rank > set[v2_root].rank){
		set[v2_root].parent = v1_root;
	}else{
		set[v2_root].parent = v1_root;
		set[v1_root].rank++;
	}
}

bool cmp(Edge e1,Edge e2){
	return e1.weight<e2.weight ; 
}

void Kruskals(Edge *input,int n,int e){
	sort(input,input+e,cmp);
	Edge *output = new Edge[n-1];
	Set *set = new Set[n];
	for(int i=0;i<n;i++){
		set[i].parent = i;
		set[i].rank = 0;
	}
	int counter = 0, i = 0;
	while(counter<n-1){
		Edge currentEdge = input[i];
		int sourceParent = find(set,currentEdge.src);
		int destinationParent = find(set , currentEdge.dest);
		if(sourceParent != destinationParent){
			output[counter] = currentEdge;
			Union(set,sourceParent,destinationParent);
			counter++;
		}
		i++;
	}
	
	int totalWeight =0;
	
	for(int m=0;m<n-1;m++){
//		cout<<output[m].src<<"-->"<<output[m].dest<<" with weight "<<output[m].weight<<endl;
		totalWeight += output[m].weight;
	}
	cout<<totalWeight<<endl;
}

signed main(){
	
//	cout<<"main1->";
	
	int n,e;
	cin>>n>>e;
	Edge *input = new Edge[e];
	for(int i=0;i<e;i++){
		int s,d,w;
		cin>>s>>d>>w;
		input[i].src = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	Kruskals(input,n,e);
	
	return 0;
}
