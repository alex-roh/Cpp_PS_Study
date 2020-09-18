#include <iostream>
#include <vector>

using namespace std;

int cache[10];

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	// init
	int cacheSize, numOfTask;
	cin >> cacheSize >> numOfTask;
	vector<int> taskVector(numOfTask);
	for(int i = 0; i < numOfTask; i++) cin >> taskVector[i];
	
	int currentTaskNum = 0;
	while(currentTaskNum < numOfTask){
		
		int currentTask = taskVector[currentTaskNum];
		bool cacheMiss = true;
		
		for(int i = 0; i < cacheSize; i++){
			// cache hit
			if(cache[i] == currentTask){
				cacheMiss = false;
				int pos = i;
				while(pos != 0){
					cache[pos] = cache[pos - 1];
					pos--;
				}
				cache[0] = currentTask;
			}
		}
		
		// cache miss
		if(cacheMiss){
			for(int pos = cacheSize - 1; pos >= 0; pos--){
				cache[pos] = cache[pos - 1];
			}
			cache[0] = currentTask;
		}
		
		currentTaskNum++;
	}
	
	for(int i = 0; i < cacheSize; i++){
		cout << cache[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
