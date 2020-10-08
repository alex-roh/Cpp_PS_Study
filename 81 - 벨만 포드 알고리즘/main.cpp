#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

int dist[101];

struct Edge{
	int source;
	int dest;
	int cost;
	
	Edge(int s, int d, int c){
		source = s;
		dest = d;
		cost = c;
	}
};

int main(){
	
	freopen("input.txt", "rt", stdin);
	vector<Edge> edges;
	
	int vertexSize, edgeSize;
	cin >> vertexSize >> edgeSize;
	
	for(int i = 1; i <= edgeSize; i++){
		int source, dest, cost;
		cin >> source >> dest >> cost;
		edges.push_back(Edge(source, dest, cost));	
	}
	
	for(int i = 1; i <= vertexSize; i++){
		dist[i] = INT_MAX;
	}
	
	dist[1] = 0;
	
	// iterate for (n - 1)
	for(int i = 1; i < vertexSize; i++){  
		for(int j = 0; j < edges.size(); j++){
			
			int source = edges[j].source;
			int dest = edges[j].dest;
			int cost = edges[j].cost;
			
			if(dist[source] != INT_MAX && dist[source] + cost < dist[dest]){
				dist[dest] = dist[source] + cost;
			}
		}
	}
	
	// iterate for n
	for(int i = 0; i < edges.size(); i++){
		
		int source = edges[i].source;
		int dest = edges[i].dest;
		int cost = edges[i].cost;
		
		if(dist[source] != INT_MAX && dist[source] + cost < dist[dest]){
			cout << -1;
			exit(0);
		}
	
	}
	
	cout<< dist[vertexSize];
	
	return 0;
}
