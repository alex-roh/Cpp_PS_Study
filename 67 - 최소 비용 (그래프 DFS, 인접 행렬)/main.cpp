#include <iostream>
#include <limits>

using namespace std;

int map[21][21];
bool check[21];
int target;
int sum;
int minVal = INT_MAX;
int numOfVertices, numOfEdges;

void DFS(int vertex){
	
	if(vertex == target){
		if(sum < minVal) minVal = sum;
		return;
	}
	else{
	
		for(int i = 1; i <= numOfVertices; i++){
			if(map[vertex][i] != 0 && check[i] == false){
				sum += map[vertex][i];
				check[vertex] = true;
				DFS(i);
				sum -= map[vertex][i];
				check[vertex] = false;
			}
		}	
		
	}
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);

	cin >> numOfVertices >> numOfEdges;
	target = numOfVertices;
	for(int i = 0; i < numOfEdges; i++){
		int source, dest, weight;
		cin >> source >> dest >> weight;
		map[source][dest] = weight;
	}
	
	check[1] = true;
	DFS(1);
	
	cout << minVal;
	
	return 0;
}
