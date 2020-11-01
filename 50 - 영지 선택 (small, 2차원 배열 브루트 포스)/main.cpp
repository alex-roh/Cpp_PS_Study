#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	// init and take input
	int width, height;
	cin >> height >> width;
	int** grid = (int**)malloc(sizeof(int*)*height);
	for(int i = 0; i < height; i++){
		grid[i] = (int*)malloc(sizeof(int)*width);
		for(int j = 0; j < width; j++){
			cin >> grid[i][j];
		}
	}
	int myWidth, myHeight;
	cin >> myHeight >> myWidth;
	
	int max = -1, sum;
	bool endIteration = false;
	
	for(int i = 0; i < height - myHeight + 1; i++){
		for(int j = 0; j < width - myWidth + 1; j++){
			sum = 0;
			for(int k = i; k < i + myHeight; k++){
				for(int m = j; m < j + myWidth; m++){ // skip l
					sum += grid[k][m];
				}
			}	
			if(endIteration) break;
			if(sum > max) max = sum;
		}
		if(endIteration) break;
	}
	
	cout << max;
	
	return 0;
}
