#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int n, factor;
	cin >> n;
	vector<int> res(n + 1);
	
	// 수 2 ~ n까지 
	for(int i = 2; i <= n; i++){
		int num = i;
		// 소인수분해 
		factor = 2;
		while(true){
			// 현재 factor로 인수분해가 가능하면 가능할 때까지 나눔 
			if(num % factor == 0){
				res[factor]++;
				num /= factor;
			}
			else factor++; // 불가능하면 factor를 1 증가시킴 
			// num이 1이 되면 소인수분해가 끝난 것이므로 빠져나옴 
			if(num == 1) break;
		}
	}
	
	cout << n << "! = ";
	for(int i = 2; i <= n; i++){
		if(res[i] != 0) cout << res[i] << " ";
	}
			
	return 0;
}
