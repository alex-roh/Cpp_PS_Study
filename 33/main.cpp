#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	for(int i = 0; i < n - 1; i++){
		int maxIndex = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] > arr[maxIndex]) maxIndex = j;
		}
		int temp = arr[i];
		arr[i] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
	
	int cnt = 1, cursor = 0;
	while(cnt < 3){
		if(arr[cursor] != arr[cursor + 1]) cursor++;
		else {
			while(arr[cursor] == arr[cursor + 1]) cursor++;
			cursor++;
		}
		cnt++;
	}
	
	cout << arr[cursor];
	
	return 0;
}
