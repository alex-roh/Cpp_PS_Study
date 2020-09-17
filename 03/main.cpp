#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	int n, i = 1, sum = 1; 
	
	cin >> n;
	cout << i;
	for(i = 2; i < n; i++){
		if(n % i == 0){
			cout << " + " << i;
			sum += i;
		}
	}
	
	cout << " = " << sum;
	
	return 0;
}
