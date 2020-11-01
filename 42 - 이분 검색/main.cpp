#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i]; 
	
	sort(arr.begin(), arr.end());
	
	int l = 0;
	int r = n - 1;
	
	while(l <= r){
		
		int mid = l + ((r - l) / 2); // overflow protection
		
		// if m is at the lower part
		if(m < arr[mid]){
			// down r
			r = mid - 1;
		}
		// if m is at the upper part
		else if(m > arr[mid]){
			// up l
			l = mid + 1;
		}
		else{
			cout << mid + 1;	
			break;
		}
	}
	
	return 0;
}
