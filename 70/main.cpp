#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int numOfVertices, numOfEdges;
vector<int> list[21];
bool visitedVertices[21];
vector<int> minDistanceFromOne(21);

void BFS(int startVertex){

	queue<int> myqueue;
	myqueue.push(startVertex);
	visitedVertices[startVertex] = true;
	while(!myqueue.empty()){
		
		int node = myqueue.front();
		myqueue.pop();
		for(int i = 0; i < list[node].size(); i++){
			if(visitedVertices[list[node][i]] == false){
				visitedVertices[list[node][i]] = true;
				myqueue.push(list[node][i]);
				minDistanceFromOne[list[node][i]] += minDistanceFromOne[node] + 1;
			}
		}
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	cin >> numOfVertices >> numOfEdges;
	for(int i = 0; i < numOfEdges; i++){
		int source, dest;
		cin >> source >> dest;
		list[source].push_back(dest);
	}
	
	visitedVertices[1] = true;
	BFS(1);
	
	for(int i = 2; i <= numOfVertices; i++){
		cout << i << " : " << minDistanceFromOne[i] << "\n";
	}
	
	return 0;
}
