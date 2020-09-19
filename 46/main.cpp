#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int taskCnt, blackoutTime;
	cin >> taskCnt;
	vector<int> tasks(taskCnt);
	for(int i = 0; i < taskCnt; i++) cin >> tasks[i];
	cin >> blackoutTime;
	
	int pos = 0, time = 0, finishedTasksCnt = 0;
	
	// operate until blackout
	while(time < blackoutTime){
		
		// only operates on unfinished tasks
		if(tasks[pos] > 0){
			tasks[pos]--;
			if(tasks[pos] == 0) finishedTasksCnt++;
			time++;
		}
		
		// if every tasks has finished
		if(finishedTasksCnt == taskCnt){
			break;
		}
		
		// move to next task
		pos++;
		if(pos == taskCnt) pos %= taskCnt;
	}
	
	// has every task done?
	if(finishedTasksCnt == taskCnt){
		cout << -1;
		return 0;
	}
	
	// find the next task
	while(tasks[pos] == 0){
		pos++;
		if(pos == taskCnt) pos %= taskCnt;
	}
	
	cout << pos + 1;
	
	return 0;
}
