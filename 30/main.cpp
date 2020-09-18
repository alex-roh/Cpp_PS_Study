#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	int n, res = 0;
	cin >> n;
	int leftNum = 1, rightNum, currentDigit, base = 1;
	
	while(leftNum > 0){
		currentDigit = (n / base) % 10; // e.g., (12345 / 1) % 10 = 5, (12345 / 10) % 10 = 4 
		leftNum = n / (base * 10); // e.g., 12345 / (1 * 10) = 1234
		rightNum = n % base; // e.g., 12345 % 1 = 0, 12345 % 10 = 5, 12345 % 100 = 45
		
		// currentDigit이 3 이상일 경우
		if(currentDigit > 3){
			// 12345의 경우
			// 00003
			// ....
			// 12343
			// or
			// 00030
			// ....
			// 1233(0~9)
			res += (leftNum + 1) * base;
		} 
		// currentDigit이 3일 경우 
		else if(currentDigit == 3){
			// 12345의 경우
			// 00300
			// ....
			// 113(0~99)
			// 123(0~45) 
			res += (leftNum * base) + (rightNum + 1); 
		}
		// currentDigit이 3 이하일 경우 
		else{
			// 12345의 경우
			// 03000
			// ....
			// 03999
			res += leftNum * base;
		}
		
		base *= 10;
	}
	
	cout << res;
	
	return 0;
}
