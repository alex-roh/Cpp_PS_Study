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
		
		// �� ���� �Ÿ��� ���� ���������ٸ� ť�� ����� �� ū �Ÿ��� ���캼 �ʿ䰡 ���� 
		if(curDist < dists[curVertex]) continue;
		
		// vertex�� ����� ������ Ž�� 
		for(int i = 0; i < graph[curVertex].size(); i++){
			
			int nextVertex = graph[curVertex][i].destVertex;
			// curDist -> ���� �������� ���� ���� �ʿ��� �Ÿ�
			// graph[curVertex][i].distance -> ���� �������� ���� ���� �ʿ��� �Ÿ� 
			int nextDist = curDist + graph[curVertex][i].distance;
			
			// �����ؾ� �ϴ� ��쿡�� ť�� push
			if(nextDist < dists[nextVertex]){
				dists[nextVertex] = nextDist; // ���Ž�Ŵ
				// ���ŵ� �Ÿ��� ���ļ� �ٸ� ���� �� �� �ֵ��� ť�� push  
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
