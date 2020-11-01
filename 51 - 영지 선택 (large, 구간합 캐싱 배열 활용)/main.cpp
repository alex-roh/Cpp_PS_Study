#include <iostream>

using namespace std;

int grid[701][701];
int partialSumTable[702][702];

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int height, width;
	cin >> height >> width;
	
	// caching partial sum
	for(int i = 1; i <= height; i++){
		for(int j = 1; j <= width; j++){
			cin >> grid[i][j];
			partialSumTable[i][j] = partialSumTable[i-1][j] + partialSumTable[i][j-1]
									- partialSumTable[i-1][j-1] + grid[i][j];	
		}
	}
	
	int myHeight, myWidth;
	int mightBeMax, max = -1;
	cin >> myHeight >> myWidth;
	
	for(int i = myHeight; i <= height; i++){
		for(int j = myWidth; j <= width; j++){
			mightBeMax = partialSumTable[i][j]
						- partialSumTable[i - myHeight][j]
						- partialSumTable[i][j - myWidth]
						+ partialSumTable[i - myHeight][j - myWidth];
			if(max < mightBeMax) max = mightBeMax;
		}
	}
	
	cout << max;

	return 0;
}
