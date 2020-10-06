#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	
	int destination;
	int cost;
	
	Edge(int dest, int c){
		destination = dest;
		cost = c;
	}
	
	bool operator < (const Edge &b) const {
		return cost > b.cost;
	}
	
};

vector<pair<int, int>> cities[101];

int main(int argc, char** argv) {	
	
	freopen("input.txt", "rt", stdin);
	
	int vertexSize, edgeSize;
	cin >> vertexSize >> edgeSize;
	
	int source, dest, weight;
	for(int i = 0; i < edgeSize; i++){
		cin >> source >> dest >> weight;
		cities[source].push_back(make_pair(dest, weight));
		cities[dest].push_back(make_pair(source, weight));	
	}
	
	priority_queue<Edge> myPQueue;
	
	myPQueue.push(Edge(source, 0));
	vector<bool> visited(vertexSize + 1);
	int totalCost = 0;
	
	while(!myPQueue.empty()){
		
		Edge edge = myPQueue.top();
		myPQueue.pop();
		
		// 트리에 추가될 정점이 선택됨 
		int vertex = edge.destination;
		int cost = edge.cost;
		
		if(visited[vertex] == false){
			visited[vertex] = true;
			totalCost += cost;
			
			// 트리에 방금 추가된 정점에서 간선을 통해 갈 수 있는 정점들을 찾음 
			for(int i = 0; i < cities[vertex].size(); i++){
				pair<int, int> candidate = cities[vertex][i];
				if(visited[candidate.first] == false)
					myPQueue.push(Edge(candidate.first,
									   candidate.second));
			}
		}
	}
	
	cout << totalCost;
	
	
	return 0;
}
