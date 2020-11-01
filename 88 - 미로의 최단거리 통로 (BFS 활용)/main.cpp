#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int grid[9][9];
pair<int, int> directions[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Node{
	
	int row;
	int col;
	int distance;
	
	Node(int r, int c, int d){
		row = r;
		col = c;
		distance = d;
	}
	
};

int BFS(){
	
	queue<Node> pathsToGo;
	
	pathsToGo.push(Node(1, 1, 0));
	
	while(!pathsToGo.empty()){
		
		Node startCell = pathsToGo.front();
		pathsToGo.pop();

		if(startCell.row == 7 && startCell.col == 7)
			return startCell.distance;
	
		for(int k = 0; k < 4; k++){
			
			int newRow = startCell.row + directions[k].first;
			int newCol = startCell.col + directions[k].second;
			
			if(grid[newRow][newCol] == 0 
				&& newRow > 0 && newRow < 8
				&& newCol > 0 && newCol < 8){
				grid[newRow][newCol] = 1;
				pathsToGo.push(Node(newRow, newCol, startCell.distance + 1));	
			}
		}			
	}
	
	return -1;
}

int main(int argc, char** argv) {

	freopen("input.txt", "rt", stdin);
	
	for(int i = 1; i <= 7; i++){
		for(int j = 1; j <= 7; j++){
			int input;
			cin >> grid[i][j];
		}
	}
	
	int minVal = BFS();
	
	cout << minVal;
	
	return 0;
}
