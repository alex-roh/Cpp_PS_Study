#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	int n, bound;
	int curr;
	int curSec = 0, maxSec = -1;
	bool flag = false;
	cin >> n >> bound;
	
	for(int i = 0; i < n; i++){
		cin >> curr;
		if(curr > bound) curSec++;		
		else {
			if(maxSec < curSec) maxSec = curSec;
			curSec = 0;
		}
	}
	
	// max를 업데이트하는 로직은 맨 마지막에도 들어가 있어야 함 
	if(maxSec < curSec) maxSec = curSec;
	
	cout << maxSec;
	
	return 0;
}
