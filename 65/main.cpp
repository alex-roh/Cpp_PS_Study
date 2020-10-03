#include <iostream>
#define N 7
#define VISITED 3

using namespace std;

int map[N + 2][N + 2];
int cnt;

typedef struct{
	int row;
	int col;
} Dir;

Dir cardinal[4] = {{-1,0}, {0,1}, {1, 0}, {0,-1}}; // N E S W
int direction = 0;

void DFS(int row, int col){
	
	// already visited
	if(map[row][col] == VISITED){
		return;
	}
	// wall
	else if(map[row][col] == 1){
		return;
	}
	
	map[row][col] = VISITED;
	
	// goal
	if(row == 7 && col == 7){
		cnt++;
		map[row][col] = 0;
		return;
	}
	else{
		
		for(int i = 0; i < 4; i++){
			DFS(row + cardinal[direction + i].row, 
				col + cardinal[direction + i].col);
		}
	}
	
	map[row][col] = 0;
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	// block the edges of the maze
	for(int i = 0; i <= N + 1; i++){
		map[0][i] = 1;
		map[i][0] = 1;
		map[N + 1][i] = 1;
		map[i][N + 1] = 1;
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> map[i][j];
		}
	}
	
	DFS(1, 1);
	
	cout << cnt;
	
	return 0;
}
