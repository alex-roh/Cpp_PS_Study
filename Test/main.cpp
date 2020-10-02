#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	int arr[9] = {47, 47, 70, 45, 23, 65, 3, 41, 44};
	sort(arr, arr + 9);
	
	for(int i = 0; i < 9; i++){
		cout << arr[i] << " ";
	} cout << "\n";
	
	int* upperPointer = upper_bound(arr, arr+9, 43);
	cout << "upperPointer = " << *upperPointer;
	
	return 0;
}
