#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

int numOfVertices, numOfEdges;
int target;
int sum;
int minVal = INT_MAX;
vector<pair<int, int>> list[21];
bool visited[21];

void DFS(int vertex){
	
	if(vertex == target){
		if(sum < minVal) minVal = sum;
		return;
	}
	else{
		
		for(int i = 0; i < list[vertex].size(); i++){
			
			if(visited[list[vertex][i].first] == false){
				
				visited[list[vertex][i].first] = true;
				sum += list[vertex][i].second;
				DFS(list[vertex][i].first);
				sum -= list[vertex][i].second;
				visited[list[vertex][i].first] = false;
			
			}
		}
	}
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	cin >> numOfVertices >> numOfEdges;
	target = numOfVertices;
	
	for(int i = 0; i < numOfEdges; i++){
	
		int source, dest, weight;
		cin >> source >> dest >> weight;
		list[source].push_back(make_pair(dest, weight));
		
	}
	
	visited[1] = true;
	DFS(1);
	
	cout << minVal;
	
	return 0;
}
