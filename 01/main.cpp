#include <iostream>

using namespace std;

int main(int argc, char** argv){
	
	int n, m, sum = 0;
	
	cin >> n;
	cin >> m;
	
	for(int i = 1; i <= n; i++) {
		if(i % m == 0) sum += i;
	}
	
	cout << sum << endl;
	
	return 0;
}

