#include <iostream>

using namespace std;

void printNumRecursive(int num){
	// 재귀함수는 반드시 종료지점을 설정 
	if(num != 1) printNumRecursive( num - 1 );
	cout << num << " ";
}

int main(int argc, char** argv) {
	
	int num;
	cin >> num;
	
	printNumRecursive(num);
	
	return 0;
}
