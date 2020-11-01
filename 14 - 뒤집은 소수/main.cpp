#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int reverse(int x);
bool isPrime(int x);

int main(){
	
	int n, x, prime;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> x;
		prime = reverse(x);
		if(isPrime(prime)) cout << prime << " ";
	}
	
	return 0;
}

int reverse(int x){
	
	int res = 0;
	int cnt = 0;
	int temp = x;
	int base = 1;
	
	while(temp){
		if(cnt > 0) base *= 10;
		temp /= 10;
		cnt++;
	}
	
	while(cnt--){
		res += (x % 10) * base;
		base /= 10;
		x /= 10;	
	}
	
	return res;
}

bool isPrime(int x){
	
	// 1은 소수가 아니므로 곧바로 false를 반환한다 
	if(x == 1) return false;
	
	bool res = false;
	vector<bool> sieve(x + 1, false);
		
	for(int i = 2; i <= sqrt(x); i++){
		if(sieve[i]) continue;
		// j = i + i로 시작해야 함을 명심 (e.g., 2, 3은 소수이므로 칠하지 말아야 한다.) 
		for(int j = i + i; j <= x; j += i){
			sieve[j] = true;
		}
	}
	
	// x가 소수인 경우 
	if(!sieve[x]) res = true;
	// x가 소수가 아닌 경우 
	else res = false; 
	
	return res;
}


