#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	// init
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> grade(n, 1);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	// logic
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[j] > arr[i]) grade[i]++;		
		}
		cout << grade[i] << " ";
	}
	
	return 0;
}
