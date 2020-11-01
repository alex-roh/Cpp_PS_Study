#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	vector<int> arr(n + 1) ;
	vector<int> inversionSequence(n + 1);
	for(int i = 1; i <= n; i++) cin >> inversionSequence[i];
	
	// traverse sequence
	for(int i = 1; i <= n; i++){
		// find position
		int cnt = -1;
		for(int j = 1; j <= n; j++){
			if(arr[j] == 0){
				cnt++;
			}
			if(cnt == inversionSequence[i]){
				arr[j] = i;
				break;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}
