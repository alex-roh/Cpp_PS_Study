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
	
	// dist 배열은 1차원으로도 사용할 수 있음 : 순차적 진행 + 1 전의 정보만 필요
	for(int i = 1; i <= vertexSize; i++){
		dist[i] = INT_MAX;
	}
	
	// 1이 출발 지점이므로 0으로 초기화
	dist[1] = 0;
	
	// 사이클이 없을 때 간선의 최대 사용 수는 (정점의 개수 - 1) 
	for(int i = 1; i < vertexSize; i++){  
		// 입력으로 받아들인 모든 엣지를 순회하며 dist 배열을 업데이트
		for(int j = 0; j < edges.size(); j++){
			
			int source = edges[j].source;
			int dest = edges[j].dest;
			int cost = edges[j].cost;
			
			// 해당 간선을 이용해 dest까지 이동할 때, 캐싱된 값보다 적으면 업데이트
			if(dist[s] != INT_MAX && dist[source] + cost < dist[dest]){
				dist[dest] = dist[source] + cost;
			}
		}
	}
	
	// 간선의 사용 개수가 정점의 개수일 때 최소값이 발견되면 음의 사이클이 존재함
	for(int j = 0; j < edges.size(); j++){
		
		int source = edges[j].source;
		int dest = edges[j].dest;
		int cost = edges[j].cost;
			
		if(dist[s] != INT_MAX && dist[source] + cost < dist[dest]){
			dist[dest] = dist[source] + cost;
		}
	}
	
	cout << dist[vertexSize];
	return 0;

}
