#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	
	int n, temp, digit = 0, res = 0;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		temp = i;
		// 각 수마다 digit에 3이 있는지 확인 
		while(temp > 0){
			digit = temp % 10;
			if(digit == 3) res++;
			temp /= 10;
		}
	}
	
	cout << res;
	
	return 0;
}
