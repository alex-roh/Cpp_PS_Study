#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i]; 
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			// 현재 수가 양수이고 오른쪽 수가 음수라면 
			if(arr[j] > 0 && arr[j + 1] < 0){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
