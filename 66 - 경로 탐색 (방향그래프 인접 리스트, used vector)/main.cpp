#include <iostream>
#include <vector>

using namespace std;

bool visited[30];
int cnt;
int target;

vector<int> map[30]; // vector 30�� ���� 

void DFS(int vertex){

	if(vertex == target){
		cnt++;
		return;
	}	
	else{
		
		for(int i = 0; i < map[vertex].size(); i++){
			
			vector<int> currentVertex = map[vertex];
			int nodeToVisit = currentVertex[i];
			
			// �ش� ����(currentVertex)�� ���(nodeToVisit)�� �湮�ߴ°�? 
			if(visited[nodeToVisit] == false){
				visited[nodeToVisit] = true;
				DFS(nodeToVisit); // �ش� ��� �湮
				visited[nodeToVisit] = false;
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
		// ���� ����Ʈ ���� 
		map[source].push_back(dest);
	}
	
	visited[1] = true;
	DFS(1);
	
	cout << cnt;
	
	return 0;
}
