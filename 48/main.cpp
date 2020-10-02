#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int n = 9;
	int** grid = (int**)malloc(sizeof(int*)*n);	
	for(int i = 0; i < n; i++){
		grid[i] = (int*)malloc(sizeof(int)*n);
		double sum = 0;
		
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
			sum += grid[i][j];
		}
		
		// get the average
		double average = round(sum / n);
		cout << average << " ";
		
		// sort and find the closest values
		sort(grid[i], grid[i] + n);
		
		int* sameOrLowerPointer = lower_bound(grid[i], grid[i] + n, average);
		int* lowerPointer = lower_bound(grid[i], grid[i] + n, average);
		lowerPointer--; // go one back
		
		int sameOrLowerOffset = abs(*sameOrLowerPointer - average);
		int lowerOffset = abs(*lowerPointer - average);
		
		/* if *sameOrLowerPointer is equal to everage 
		 or its offset is less than or equal to *lowerPointer */
		if(sameOrLowerOffset == 0 || sameOrLowerOffset <= lowerOffset)
			cout << *sameOrLowerPointer << "\n";
		else cout << *lowerPointer << "\n";
		
	}
	
	return 0;
}
