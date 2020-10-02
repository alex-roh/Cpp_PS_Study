#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int cachingTable[1501];

int main(int argc, char** argv) {
	
	int target;
	cin >> target;
	
	int pos = 1;
	cachingTable[pos++] = 1;
	
	int p2 = 1, p3 = 1, p5 = 1;
	int min = INT_MAX;
	
	while(pos <= target){
		
		int p2_num = cachingTable[p2] * 2;
		int p3_num = cachingTable[p3] * 3;
		int p5_num = cachingTable[p5] * 2;
		
		// compare p2 and p3 and fill min
		if(p2_num < p3_num) min = p2_num;
		else min = p3_num;
		
		// compare p5 and min
		if(p5_num < min) min = min = p5_num;
		
		// check if there's an equivalent of min
		if(p2_num == min) p2++;
		if(p3_num == min) p3++;
		if(p5_num == min) p5++;
	
		cachingTable[pos] = min;
	
		pos++;
	}
	
	cout << cachingTable[target];
	
	return 0;
}
