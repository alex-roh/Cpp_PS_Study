#include <iostream>
#include <string>
#include <vector>
#define MAX 129

using namespace std;

int main(int argc, char** argv) {
	
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	
	vector<int> ascii(MAX, 0);
	
	for(int i = 0; i < str1.size(); i++){
		ascii[(int)str1.at(i)]++;
		ascii[(int)str2.at(i)]--;
	}
	
	for(int i = 0; i < MAX; i++){
		if(ascii[i] != 0){
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";
	return 0;
}
