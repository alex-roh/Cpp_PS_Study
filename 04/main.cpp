#include <iostream>
#define MAX 12000

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	int n;
	int least = MAX, largest = 0;
	int temp;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(least > temp) least = temp;
		if(largest < temp) largest = temp;
	}
	
	cout << largest - least;
	
	return 0;
}
