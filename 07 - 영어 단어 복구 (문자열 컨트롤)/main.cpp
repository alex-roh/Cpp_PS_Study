#include <iostream>
#include <string>
#define MAX 101

using namespace std;

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	string str, res;
	char temp;
	int offset = 'a' - 'A';
	getline(cin, str);
	
	// 공백을 제거한 res 문자열을 생성 
	for(int i = 0; i < str.size(); i++){
		if(str.at(i) == ' ') continue;
		else res += str.at(i);
	}
	
	// 소문자로 변환하여 출력
	for(int i = 0; i < res.size(); i++){
		// 대문자일 경우 
		if(res.at(i) >= 'A' && res.at(i) <= 'Z'){
			// 소문자로 변환
			temp = (char) res.at(i) + offset;
			res[i] = temp;
		}
	} 
	
	cout << res;
	
	return 0;
}
