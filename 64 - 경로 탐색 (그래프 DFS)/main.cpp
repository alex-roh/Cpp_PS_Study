#include <iostream>

using namespace std;

int numOfVertices;
int numOfEdges;
int map[21][21];
bool visited[6]; // �湮�ߴ� ���� �ٽ� �湮���� �ʱ� ���� �迭 
int cnt;

void DFS(int level){
	
	if(level == numOfVertices){
		cnt++;
		return;
	}
	else{
		for(int i = 1; i <= numOfVertices; i++){
			// ������ �湮���� �ʾ����鼭 ���� �ִ� ������ ã�� 
			if(map[level][i] == 1 && visited[i] == false){
				visited[i] = true;
				DFS(i);
				visited[i] = false;
			}
		}	
	}
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	cin >> numOfVertices >> numOfEdges;
	
	for(int i = 1; i <= numOfEdges; i++){
		int source, dest;
		cin >> source >> dest;
		map[source][dest] = 1;
	}
	
	visited[1] = true;
	DFS(1);
	
	cout << cnt;
	
	return 0;
}
