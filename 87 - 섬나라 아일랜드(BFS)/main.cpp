#include <iostream>
#include <vector>
#include <queue>
#define VISITED 3

using namespace std;

int n;
int map[22][22];
int cnt;

pair<int, int> directions[8] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void BFS(){
	
	queue<pair<int, int>> myQueue;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
		
			if(map[i][j] == 1){
				
				myQueue.push(make_pair(i, j));
				
				while(!myQueue.empty()){
					pair<int, int> cell = myQueue.front();
					int row = cell.first;
					int col = cell.second; 
					map[row][col] = VISITED;
					myQueue.pop();
					
					// 현재 셀의 위, 오른쪽, 아래, 왼쪽, 대각선 방향을 탐색
					for(int k = 0; k < 8; k++){
						int rowOffset = directions[k].first;
						int colOffset = directions[k].second;
						if(map[row + rowOffset][col + colOffset] == 1){
							myQueue.push(make_pair(row + rowOffset, col + colOffset));
						}
					}
				}	
				
				cnt++;
				
			}
		}
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int val;
			cin >> val;
			map[i][j] = val;	
		}
	}
	
	BFS();
	
	cout << cnt;
	
	return 0;
}
