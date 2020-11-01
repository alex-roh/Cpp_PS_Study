#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	
	int n, i, j, cnt = 0;
	
	cin >> n;
	vector<bool> sieve(n + 1, false);
	
	for(i = 1; i <= n; i++)
		sieve[i] = 0;
	
	// 에라스토테네스의 체
	sieve[1] = true; 
	for(i = 2; i <= sqrt(n); i++){	
		if(sieve[i]) continue;
		for(j = i + i; j <= n; j += i){
			sieve[j] = true;
		}
	}
	
	for(i = 1; i <= n; i++)
		if(!sieve[i]) cnt++;
	
	cout << cnt;
	
	return 0;
}
