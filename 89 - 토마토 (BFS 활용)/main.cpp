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
		
		// 오늘 익어 있는 토마토들을 꺼내 다른 토마토들을 익힘 
		while(!ripeTomatos.empty()){
			
			pair<int, int> cell = ripeTomatos.front();
			ripeTomatos.pop();
			
			for(int i = 0; i < 4; i++){
				
				int nextRow = cell.first + directions[i].first;
				int nextCol = cell.second + directions[i].second;
				
				// 범위를 벗어난 경우 
				if(nextRow == -1 || nextRow == height || nextCol == -1 || nextCol == width)
					continue;
				// 빈 곳이거나 이미 익은 공간인 경우 
				else if(grid[nextRow][nextCol] == -1 || grid[nextRow][nextCol] == 1)
					continue;
				else{
					// 현재 익어 있는 토마토 덕분에 익은 토마토를 affectedTomatos 큐에 집어넣음
					affectedTomatos.push(make_pair(nextRow, nextCol));
					grid[nextRow][nextCol] = 1;
					ripeTomatoSize++;
				}	
			}		
			
			// 모든 토마토가 다 익었으면 탈출
			if(ripeTomatoSize == gridSize)
				return day; 
			
		}
		
		// 오늘 익은 토마토들(affectedTomatos)을 이미 익은 토마토(ripeTomatos)들로 옮김 
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
