#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int numOfVertices; // 정점의 개수 
	int numOfEdges;    // 간선의 개수 
	
	cin >> numOfVertices >> numOfEdges;
	vector<vector<int>> adjMatrix(numOfVertices + 1, vector<int>(numOfVertices + 1, 0));
	
	for(int i = 0; i < numOfEdges; i++){
		int source, dest, weight;
		cin >> source >> dest >> weight;
		adjMatrix[source][dest] = weight;
	}
	
	for(int i = 1; i <= numOfVertices; i++){
		for(int j = 1; j <= numOfVertices; j++){
			cout << adjMatrix[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
