#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	int a, b, sum = 0;
	
	cin >> a >> b;
	
	for(int i = a; i <= b; i++){
		sum += i;
		if(i != b) cout << i << " + ";
		else cout << i << " = " << sum;
	}
	
}
