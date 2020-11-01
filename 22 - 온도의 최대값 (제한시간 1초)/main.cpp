#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	// init
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	
	int startPos = 0, endPos;
	int sum = 0;
	
	// 1. 연속적인 며칠동안의 온도의 합을 구함
	for(int i = 0; i < k; i++){
		sum += arr[i];
		endPos = i;
	}
	
	int max = sum;
	
	// 2. 마지막 원소가 포함될 때까지 연속합을 구함
	while(endPos != n - 1){
		sum -= arr[startPos++];
		sum += arr[++endPos];
		if(max < sum) max = sum;
	} 
	
	cout << max;
	
	return 0;
}
