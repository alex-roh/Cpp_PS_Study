#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int numOfPrinces, targetCnt;
	queue<int> princeQueue;
	cin >> numOfPrinces >> targetCnt;
	
	for(int i = 1; i <= numOfPrinces; i++){
		princeQueue.push(i);
	}
	
	int cnt, lastPrince;
	while(!princeQueue.empty()){
		
		int prince = princeQueue.front();
		cnt++;
		princeQueue.pop();
		
		if(cnt == targetCnt){
			lastPrince = prince;
			cnt = 0;
		}
		else{
			princeQueue.push(prince);	
		}
	}
	
	cout << lastPrince;
	
	return 0;
}
