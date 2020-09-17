#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	int len, temp;
	int max = -1, res;
	string str;
	int arr[11] = { 0 };
	
	getline(cin, str);
	len = str.size();
	
	for(int i = 0; i < len; i++){
		temp = (int) str.at(i) - '0';
		arr[temp]++;
	}
	
	for(int i = 1; i < 11; i++){
		if(max <= arr[i]) {
			max = arr[i];	
			res = i;
		}
	}
	
	cout << res;
	
	return 0;
}
