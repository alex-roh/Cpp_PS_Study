#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	string inputStr;
	getline(cin, inputStr);
	int numOfOpenBr = 0;
	
	for(int i = 0; i < inputStr.size(); i++){
		if(inputStr[i] == '('){
			numOfOpenBr++;
		}
		else {
			if(numOfOpenBr <= 0){	
				cout << "NO";
				return 0;
			}
			else	
				numOfOpenBr--;
		}
	}
	
	if(numOfOpenBr != 0) cout << "NO";
	else cout << "YES";
	
	return 0;
}
