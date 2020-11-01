#include <iostream>
#include <queue>

using namespace std; 

bool visitedPos[10001];
int cntForPos[10001];
int dis[3] = {1, -1, 5};

void BFS(int posOfHyun, int posOfCow){
	
	queue<int> movedPosQueue;
	movedPosQueue.push(posOfHyun);
	visitedPos[posOfHyun] = true;
		
	while(true){
	
		int pos = movedPosQueue.front();
		if(pos == posOfCow) break;
		movedPosQueue.pop();
		
		for(int i = 0; i < 3; i++){
			int movedPos = pos + dis[i];
			if(visitedPos[movedPos] == false){
				visitedPos[movedPos] = true;
				movedPosQueue.push(movedPos);
				cntForPos[movedPos] = cntForPos[pos] + 1;
			}
		}
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int posOfHyun, posOfCow;
	cin >> posOfHyun >> posOfCow;
	
	BFS(posOfHyun, posOfCow);
	
	cout << cntForPos[posOfCow];
	
	return 0;
}
