#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	// init
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> flag(n + 1, 0);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	for(int i = 1; i < n; i++){
		int index = abs(arr[i] - arr[i - 1]);
		if(index < n){
			flag[index]++;	
		}
	}
	
	for(int i = 1; i < n; i++){
		if(flag[i] == 0) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	
	return 0;
}
