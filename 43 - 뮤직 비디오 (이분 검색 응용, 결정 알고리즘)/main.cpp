#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int songCnt, dvdCnt, res = 0;
	cin >> songCnt >> dvdCnt;
	vector<int> songList(songCnt);
	int songTotalLength = 0, maxSongLength = -1;
	for(int i = 0; i < songCnt; i++) {
		cin >> songList[i];
		songTotalLength += songList[i];
		if(maxSongLength < songList[i]) maxSongLength = songList[i];
	}
	
	int lowerBound = maxSongLength;
	int upperBound = songTotalLength;
	
	while(lowerBound <= upperBound){
		
		int middle = lowerBound + ((upperBound - lowerBound) / 2);
		
		// get dvd cnt at the current middle value
		int cnt = 1, partialSum = 0;
		for(int i = 0; i < songCnt; i++){
			if(partialSum + songList[i] > middle){
				cnt++;
				partialSum = songList[i];
			}
			else partialSum += songList[i];
		}
		
		if(cnt <= dvdCnt){
			// cache shrink
			upperBound = middle - 1;
			res = middle;
		}
		else if(cnt > dvdCnt){
			// enlarge
			lowerBound = middle + 1;
		}
	}
	
	cout << res;
	
	return 0;
}
