#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	int input;
	cin >> input;
	
	int count = 0;
	int subtrahend = 0; // if (a - 1, a, a + 1), 1 is the subtrahend
	int divisor = 2; // if 15/2, 2 is the divisor
	int borderQuotient = input / divisor; // if input is 15, end iteration at 7 
	
	while(divisor < borderQuotient){
	
		int curQuotient = input / divisor;
		int curRemainder = input % divisor;
	
		if((divisor % 2 != 0 && curRemainder == 0) 
		|| (divisor % 2 == 0 && curRemainder == divisor / 2)){
			// if 2a + 1 : a, a + 1, 0 is the subtrahend
			// if 3a : a - 1, a, a + 1, 1 is the subtrahend
			// if 4a + 2 : a - 1, a, a + 1, a + 2, 1 is the subtrahend
			// if 5a : a - 2, a - 1, a, a + 1, a + 2, 2 is the subtrahend
			int start = curQuotient - subtrahend;
			if(curQuotient - subtrahend <= 0) break;
			else cout << start;
			for(int i = 1; i < divisor; i++)
				cout << " + " << curQuotient - subtrahend + i;
			cout << " = " << input << "\n";
			count++;
		}
		divisor++;
		if(divisor % 2 != 0) subtrahend++;
	}
		
	cout << count;
	return 0;
	
}
