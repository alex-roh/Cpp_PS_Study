#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	int n, sum = 0, temp = 1;
	cin >> n;
	vector<int> factors(n + 1, 1);
	
	for(int i = 2; i < factors.size(); i++){
		for(int j = i; j <= n; j += i){
			factors[j]++;
		}
	}
	
	for(int i = 1; i < factors.size(); i++){
		cout << factors[i] << " ";
	}
	
	return 0;
}
