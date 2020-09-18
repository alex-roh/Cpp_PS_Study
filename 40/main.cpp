#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int aSize, bSize;
	cin >> aSize;
	vector<int> aSet(aSize);
	for(int i = 0; i < aSize; i++) cin >> aSet[i];
	cin >> bSize;
	vector<int> bSet(bSize);
	for(int i = 0; i < bSize; i++) cin >> bSet[i];
	
	// sort
	sort(aSet.begin(), aSet.end());
	sort(bSet.begin(), bSet.end());
	
	int aPos = 0, bPos = 0;
	while(aPos < aSize && bPos < bSize){
		if(aSet[aPos] < bSet[bPos]) aPos++;
		else if(aSet[aPos] > bSet[bPos]) bPos++;
		else {
			cout << aSet[aPos] << " ";
			aPos++;
			bPos++;
		}
	}
	
	return 0;
}
