#include <iostream>
#include <vector>

using namespace std;

bool visited[30];
int cnt;
int target;

vector<int> map[30]; // vector 30개 생성 

void DFS(int vertex){

	if(vertex == target){
		cnt++;
		return;
	}	
	else{
		
		for(int i = 0; i < map[vertex].size(); i++){
			// 해당 정점(map[vertex])의 노드(map[vertex][i])를 방문했는가? 
			if(visited[map[vertex][i]] == false){
				visited[map[vertex][i]] = true;
				DFS(map[vertex][i]); // 해당 노드 방문
				visited[map[vertex][i]] = false;
			}
		}
	}
}

int main(int argc, char** argv) {

	freopen("input.txt", "rt", stdin);
	
	int numOfEdges, numOfVertices;
	cin >> numOfVertices >> numOfEdges;
	
	target = numOfVertices;
	
	for(int i = 1; i <= numOfEdges; i++){
		int source, dest;
		cin >> source >> dest;
		// 인접 리스트 생성 
		map[source].push_back(dest);
	}
	
	visited[1] = true;
	DFS(1);
	
	cout << cnt;
	
	return 0;
}
