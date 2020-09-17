#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	
	int n, cnt = 0, sum = 0, numCnt = 0;
	int temp, differ, base = 1;
	cin >> n;
	vector<int> arr(n + 1, 0);
	
	temp = n;
	while(temp){
		temp /= 10;
		cnt++;	
	}
	
	for(int i = 1; i < cnt; i++){
		numCnt += base * 9;	
		sum += base * 9 * i;
		base *= 10;
	}
	differ = n - numCnt;
	sum = sum + (differ * cnt);
	
	cout << sum;
	
	return 0;
}
