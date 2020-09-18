#include <iostream>
#include <string>
#define C 12
#define H 1

using namespace std;

int main(int argc, char** argv) {
	
	int res = 0;
	string formula;
	getline(cin, formula);
	
	// CH 꼴인 경우
	if(formula.size() == 2){
		res += C + H;
		cout << res;
	}
	else {
		int cursor = 1; // num
		string cNum, hNum;
		while(formula.at(cursor) != 'H'){
			cNum += formula.at(cursor++);
		}
		cursor++;
		while(cursor != formula.size()){
			hNum += formula.at(cursor++);
		}
		if(cNum.empty()) cNum = "1";
		if(hNum.empty()) hNum = "1";
		int cSize, hSize;
		cSize = stoi(cNum);
		res += C * cSize;
		hSize = stoi(hNum);
		res += H * hSize;
		cout << res;
	}
	
	return 0;
}
