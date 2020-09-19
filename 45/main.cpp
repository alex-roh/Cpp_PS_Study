#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char** argv) {
	
	int n, target;
	cin >> n >> target;
	deque<int> princes(n + 1);
	for(int i = 0; i < n; i++) princes[i] = i + 1;
	
	int cnt = 0, pos = 0, princeCnt = 0;
	while(princeCnt < n){
		
		if(princes[pos] != 0) cnt++;
		
		if(cnt == target){
			if(princeCnt == n - 1) cout << princes[pos] << " ";
			princes[pos] = 0;
			princeCnt++;
			cnt = 0;
		}
		
		pos++;
		if(pos >= n) pos %= n;
	}
	
	return 0;
}
