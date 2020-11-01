#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int n;
	bool flag;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	for(int i = 0; i < n; i++){
		flag = false;
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		if(!flag) break;
	}
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	
	cout << "\n";
	
	return 0;
}
