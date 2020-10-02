#include <iostream>

using namespace std;

void divideAndPrintRecursive(int num){
	
	int quotient = num / 2;
	int remainder = num % 2;
	
	// base case	
	if(quotient < 2){
		cout << quotient;
		cout << remainder;
		return;
	}
	else {
		divideAndPrintRecursive(quotient);
		cout << remainder;
	}
}

int main(int argc, char** argv) {
	
	int num;
	cin >> num;
	divideAndPrintRecursive(num);
	
	return 0;
}
