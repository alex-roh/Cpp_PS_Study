#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	int** grid = (int**)malloc(sizeof(int*) * (n + 2));
	for(int i = 0; i < n + 2; i++){
		if(i == 0 || i == n + 1){
			grid[i] = (int*)calloc(n + 2, sizeof(int));
		} else grid[i] = (int*)malloc(sizeof(int) * (n + 2));
	}	
	
	for(int i = 1; i < n + 1; i++){
		for(int j = 0; j < n + 2; j++){
			if(j == 0 || j == n + 1) {
				grid[i][j] = 0;
				continue;	
			}
			cin >> grid[i][j];
		}
	}
	
	for(int i = 0; i < n + 2; i++){
		for(int j = 0; j < n + 2; j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	int cnt = 0;
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < n + 1; j++){
			// check up, down, right, left
			if(grid[i - 1][j] < grid[i][j]
				&& grid[i + 1][j] < grid[i][j]
				&& grid[i][j + 1] < grid[i][j]
				&& grid[i][j - 1] < grid[i][j]
			)
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
