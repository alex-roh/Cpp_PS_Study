#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
	
	int n, temp, digit = 0, res = 0;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		temp = i;
		// �� ������ digit�� 3�� �ִ��� Ȯ�� 
		while(temp > 0){
			digit = temp % 10;
			if(digit == 3) res++;
			temp /= 10;
		}
	}
	
	cout << res;
	
	return 0;
}
