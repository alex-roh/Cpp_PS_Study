#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	// insertion sort
	for(int i = 1; i < n; i++){
		int elementToBeSorted = arr[i];
		int pos = i;
		// find the right position 
		while(pos != 0 && arr[pos - 1] > elementToBeSorted){
			arr[pos] = arr[pos - 1];
			pos--;
		}
		arr[pos] = elementToBeSorted;
	}
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
