#include <iostream>

using namespace std;

void printNumRecursive(int num){
	// ����Լ��� �ݵ�� ���������� ���� 
	if(num != 1) printNumRecursive( num - 1 );
	cout << num << " ";
}

int main(int argc, char** argv) {
	
	int num;
	cin >> num;
	
	printNumRecursive(num);
	
	return 0;
}
