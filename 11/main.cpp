#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	
	int n, cnt = 0, sum = 0;
	int temp, differ, base = 1;
	cin >> n;
	vector<int> arr(n + 1, 0);
	
	temp = n;
	while(temp){
		temp /= 10;
		cnt++;	
	}
	
	for(int i = 0; i < cnt - 1; i++){		
		sum += base * 9;
		base *= 10;
	}
	
	differ = n - sum;
	sum += differ * cnt;
	
	cout << sum;
	
	return 0;
}
