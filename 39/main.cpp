#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int fSize, sSize;
	cin >> fSize;
	vector<int> fArr(fSize);
	for(int i = 0; i < fSize; i++) cin >> fArr[i];
	cin >> sSize;
	vector<int> sArr(sSize);
	for(int i = 0; i < sSize; i++) cin >> sArr[i];
	vector<int> rArr;
	
	int fPos = 0, sPos = 0;
	while(fPos < fSize && sPos < sSize){
		// if an element in the first array is smaller than the second
		if(fArr[fPos] < sArr[sPos]){
			rArr.push_back(fArr[fPos]);
			fPos++;
		}
		// ... bigger than the second (or as same size)
		else if(fArr[fPos] >= sArr[sPos]){
			rArr.push_back(sArr[sPos]);
			sPos++;
		}
	}
	
	// if the first array has remnants
	while(fPos < fSize){
		rArr.push_back(fArr[fPos]);
		fPos++;
	}	
	// ... the second array
	while(sPos < sSize){
		rArr.push_back(sArr[sPos]);
		sPos++;
	}
	
	for(int i = 0; i < rArr.size(); i++) cout << rArr[i] << " ";
	
	return 0;
}
