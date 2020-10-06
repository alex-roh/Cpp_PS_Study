#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

struct Edge {
	
	int destVertex;
	int distance;
	
	Edge(int dest, int weight){
		destVertex = dest;
		distance = weight;
	}
	
	bool operator < (const Edge &edge) const {
		return distance > edge.distance; // minimum heap
	}
	
};

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int vertexSize, edgeSize;
	
	cin >> vertexSize >> edgeSize;
	vector<Edge> graph[vertexSize + 1];
	
	for(int i = 0; i < edgeSize; i++){
		
		int source, dest, cost;
		cin >> source >> dest >> cost; 
		graph[source].push_back(Edge(dest, cost));
			
	}
	
	vector<int> dists(vertexSize + 1, INT_MAX);
	priority_queue<Edge> myPQueue;
	myPQueue.push(Edge(1, 0));
	dists[1] = 0;
	
	while(!myPQueue.empty()){
	
		Edge edge = myPQueue.top();
		myPQueue.pop();
		
		int curVertex = edge.destVertex;
		int curDist = edge.distance;
		
		// 더 작은 거리에 의해 퍼져나갔다면 큐에 저장된 더 큰 거리를 살펴볼 필요가 없음 
		if(curDist < dists[curVertex]) continue;
		
		// vertex와 연결된 정점을 탐색 
		for(int i = 0; i < graph[curVertex].size(); i++){
			
			int nextVertex = graph[curVertex][i].destVertex;
			// curDist -> 현재 정점까지 오기 위해 필요한 거리
			// graph[curVertex][i].distance -> 다음 정점까지 가기 위해 필요한 거리 
			int nextDist = curDist + graph[curVertex][i].distance;
			
			// 갱신해야 하는 경우에만 큐에 push
			if(nextDist < dists[nextVertex]){
				dists[nextVertex] = nextDist; // 갱신시킴
				// 갱신된 거리를 거쳐서 다른 노드로 갈 수 있도록 큐에 push  
				myPQueue.push(Edge(nextVertex, nextDist));
			}	
		}
	}
	
	for(int i = 2; i <= vertexSize; i++){
		if(dists[i] != INT_MAX)
			cout << i << " : " << dists[i] << "\n";
		else cout << i << " : impossible" << "\n";	
	}
	
	
	return 0;
}
