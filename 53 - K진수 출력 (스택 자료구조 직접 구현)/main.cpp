#include <iostream>
#include <string>

int stack[100];
int top = -1;

using namespace std;

void push(int x){
	stack[++top] = x;
}

int pop(){
	return stack[top--];
}

int main(int argc, char** argv) {
	
	int target, base;
	cin >> target >> base;
	string str = "0123456789ABCDEF";
	
	while(target > 0){
		push(target % base);
		target /= base;
	}
	
	while(top != -1){
		cout << (char)str[pop()];
	}
	
	return 0;
}
