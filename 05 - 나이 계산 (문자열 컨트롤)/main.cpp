#include <iostream>
#include <string>

#define YEAR 2019

using namespace std;

int main(int argc, char** argv) 
{
	// freopen("input.txt", "rt", stdin);
	string str;
	int year, age;
	char sex;
	getline(cin, str);

	// 연도를 검색함	
	if(str.at(0) == '1' || str.at(1) == '0'){
		year = 2000;
	} else {
		year = 1900;
	}
	year += str.at(1) - '0';
	year += (str.at(0) - '0') * 10;
	// 나이를 계산함
	age = YEAR - year + 1;
	
	// 성별을 검색함 (문자열 길이가 길지 않으므로 조건문에 size() 호출 그대로 씀)
	int i;
	for(i = 0; i < str.size(); i++){
		if(str.at(i) == '-') break;
	} 
	if(str.at(++i) == '1'){
		sex = 'M';
	} else {
		sex = 'F';	
	}
	 
	cout << age << " " << sex << "\n";
	
	return 0;
}
