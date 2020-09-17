#include <iostream>
#include <string>
#define MAX 100

using namespace std;

int main(int argc, char** argv) {

	//freopen("input.txt", "rt", stdin);
	string str;
	string num;
	int res, res2 = 1;
	getline(cin, str);
	
	for(int i = 0; i < str.size(); i++){
		if(str.at(i) >= '0' && str.at(i) <= '9'){
			num += str.at(i);
		}
	}
	
	res = stoi(num, nullptr, 10);
	cout << res << "\n";
	
	for(int i = 1; i <= res/2; i++){
		if(res % i == 0) res2++;
	}
	
	cout << res2 << "\n";

}
