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
			// �ش� ����(map[vertex])�� ���(map[vertex][i])�� �湮�ߴ°�? 
			if(visited[map[vertex][i]] == false){
				visited[map[vertex][i]] = true;
				DFS(map[vertex][i]); // �ش� ��� �湮
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
		// ���� ����Ʈ ���� 
		map[source].push_back(dest);
	}
	
	visited[1] = true;
	DFS(1);
	
	cout << cnt;
	
	return 0;
}
