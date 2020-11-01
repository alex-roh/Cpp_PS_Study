#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int grid[1000][1000];

int width, height;
int gridSize;
int ripeTomatoSize;
queue<pair<int, int>> ripeTomatos;
queue<pair<int, int>> affectedTomatos;
pair<int, int> directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int BFS(){
	
	int day = 1;
	
	while(!ripeTomatos.empty()){
		
		// ���� �;� �ִ� �丶����� ���� �ٸ� �丶����� ���� 
		while(!ripeTomatos.empty()){
			
			pair<int, int> cell = ripeTomatos.front();
			ripeTomatos.pop();
			
			for(int i = 0; i < 4; i++){
				
				int nextRow = cell.first + directions[i].first;
				int nextCol = cell.second + directions[i].second;
				
				// ������ ��� ��� 
				if(nextRow == -1 || nextRow == height || nextCol == -1 || nextCol == width)
					continue;
				// �� ���̰ų� �̹� ���� ������ ��� 
				else if(grid[nextRow][nextCol] == -1 || grid[nextRow][nextCol] == 1)
					continue;
				else{
					// ���� �;� �ִ� �丶�� ���п� ���� �丶�並 affectedTomatos ť�� �������
					affectedTomatos.push(make_pair(nextRow, nextCol));
					grid[nextRow][nextCol] = 1;
					ripeTomatoSize++;
				}	
			}		
			
			// ��� �丶�䰡 �� �;����� Ż��
			if(ripeTomatoSize == gridSize)
				return day; 
			
		}
		
		// ���� ���� �丶���(affectedTomatos)�� �̹� ���� �丶��(ripeTomatos)��� �ű� 
		swap(affectedTomatos, ripeTomatos);
		
		day++;
	}
	
	return -1;
} 

int main(int argc, char** argv) {

	cin >> width >> height;
	bool allRipen = true;
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			cin >> grid[i][j];
			if(grid[i][j] == 0) 
				allRipen = false;
			else if(grid[i][j] == 1){
				ripeTomatos.push(make_pair(i, j));
				ripeTomatoSize++;
			}
			else if(grid[i][j] == -1){
				gridSize--;
			}
		}
	}
	
	gridSize += width * height;

	if(allRipen == true){
		cout << 0;
	}	
	else cout << BFS();
	
	return 0;
}
