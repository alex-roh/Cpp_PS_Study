#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	vector<int> outputVector(n + 1);
	vector<int> inputVector(n + 1);
	for(int i = 1; i <= n; i++) cin >> inputVector[i];
	
	for(int i = n; i >= 1; i--){
		
		// 0 0 0 0 0 0 0 8(0) -> 0 0 0 0 0 0 0 8
		// 0 0 0 0 0 0 7(1) 8 -> 0 0 0 0 0 0 8 7
		// 0 0 0 0 0 6(1) 8 7 -> 0 0 0 0 0 8 6 7
		// 0 0 0 0 5(2) 8 6 7 -> 0 0 0 0 8 6 5 7
		// ... and so on
		
		int inversionCnt = inputVector[i];	
		int pos = i;
		while(pos != n && inversionCnt > 0){
			outputVector[pos] = outputVector[pos + 1];
			inversionCnt--; pos++;
		}
		outputVector[pos] = i;
	}
	
	for(int i = 1; i <= n; i++){
		cout << outputVector[i] << " ";
	}
	
	return 0;
}
