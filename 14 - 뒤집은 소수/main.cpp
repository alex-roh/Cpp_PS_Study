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
	
	// 1�� �Ҽ��� �ƴϹǷ� ��ٷ� false�� ��ȯ�Ѵ� 
	if(x == 1) return false;
	
	bool res = false;
	vector<bool> sieve(x + 1, false);
		
	for(int i = 2; i <= sqrt(x); i++){
		if(sieve[i]) continue;
		// j = i + i�� �����ؾ� ���� ��� (e.g., 2, 3�� �Ҽ��̹Ƿ� ĥ���� ���ƾ� �Ѵ�.) 
		for(int j = i + i; j <= x; j += i){
			sieve[j] = true;
		}
	}
	
	// x�� �Ҽ��� ��� 
	if(!sieve[x]) res = true;
	// x�� �Ҽ��� �ƴ� ��� 
	else res = false; 
	
	return res;
}


