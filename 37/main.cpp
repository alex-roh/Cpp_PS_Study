#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int cacheSize, numOfTask;
	cin >> cacheSize >> numOfTask;
	deque<int> cache;
	deque<int> taskList(numOfTask);
	for(int i = 0; i < numOfTask; i++) cin >> taskList[i];
	
	while(!taskList.empty()){
		
		int currentTask = taskList.front();
		taskList.pop_front();
		bool cacheMiss = true;
				
		// search the cache to check whether the currentTask is there or not
		for(deque<int>::iterator it = cache.begin(); it != cache.end(); it++){
			if(cache.empty()) break;
			// cache hit
			if(*it == currentTask){
				cacheMiss = false;
				cache.erase(it);
				cache.push_front(currentTask);
				break;
			}
		}
		
		// cache miss
		if(cacheMiss){
			cache.push_front(currentTask);
		}
		
		// if cache had become larger than its size, shrink
		int size = cache.size();
		if(size > cacheSize) cache.resize(cacheSize);
		
	}
	
	for(deque<int>::iterator it = cache.begin(); it != cache.end(); it++){
		cout << *it << " ";
	}
	
	return 0;
}
