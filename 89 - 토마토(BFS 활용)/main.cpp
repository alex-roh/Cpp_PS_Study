#include <iostream>
#include <queue>
#include <limits>
#include <ctime>

using namespace std;

int rowSize, colSize;
int tom[1010][1010], dis[1010][1010];
int res = INT_MIN;
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {-1, 0, 1, 0};

struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};

queue<Loc> Q;

int main() {
	
	freopen("input.txt", "rt", stdin);
	clock_t start = clock();

	cin >> colSize >> rowSize;
	for(int i = 1; i <= rowSize; i++) {
		for(int j = 1; j <= colSize; j++) {
			cin >> tom[i][j];
			if(tom[i][j] == 1) {
				Q.push(Loc(i, j));
			}
		}
	}

	while(!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();

		for(int i = 0; i < 4; i++) {
			int posX = tmp.x + dx[i];
			int posY = tmp.y + dy[i];
			if(tom[posX][posY] == 0) {
				if(posX >= 1 && posX <= colSize && posY >= 1 && posY <= rowSize) {
					Q.push(Loc(posX, posY));
					tom[posX][posY] = 1;
					dis[posX][posY] = dis[tmp.x][tmp.y] + 1;
				}
			}
		}

	}

	bool isUnripeTomato = false;
	for(int i = 1; i <= rowSize; i++) {
		for(int j = 1; j <= colSize; j++) {
			if(tom[i][j] == 0) isUnripeTomato = true;
		}
	}

	if(isUnripeTomato == true) {
		for(int i = 1; i <= rowSize; i++) {
			for(int j = 1; j <= colSize; j++) {
				if(res < dis[i][j]) res = dis[i][j];
			}
		}
		cout << res;
	}
	else cout << -1;
	
	printf("\n%0.5fs\n", (float)(clock() - start)/CLOCKS_PER_SEC);
	
	return 0;
}
