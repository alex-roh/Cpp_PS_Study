#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int stallCnt, horseCnt, res; 
	cin >> stallCnt >> horseCnt;
	vector<int> stalls(stallCnt);
	for(int i = 0; i < stallCnt; i++) cin >> stalls[i];
	
	sort(stalls.begin(), stalls.end());
	
	int lowerBound = 0;
	int upperBound = stalls[stallCnt - 1] - stalls[0];
	
	while(lowerBound <= upperBound){
		
		int pivot = lowerBound + ((upperBound - lowerBound) / 2);
		
		int cnt = 1, lastHorsePos = 0;
		for(int i = 1; i < stallCnt;){
			if(stalls[i] - stalls[lastHorsePos] >= pivot){
				cnt++;
				lastHorsePos = i;
			}
			else i++;
		}
		
		// we can deploy more horses by this pivot distance
		if(cnt >= horseCnt){
			// cache, then go to the upper part
			res = pivot;
			lowerBound = pivot + 1;
		}
		// Or else : we should lower the pivot distance
		else{
			upperBound = pivot - 1;
		}
	}
	
	cout << res;
	
	return 0;
}
