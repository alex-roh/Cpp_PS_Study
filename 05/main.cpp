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

	// ������ �˻���	
	if(str.at(0) == '1' || str.at(1) == '0'){
		year = 2000;
	} else {
		year = 1900;
	}
	year += str.at(1) - '0';
	year += (str.at(0) - '0') * 10;
	// ���̸� �����
	age = YEAR - year + 1;
	
	// ������ �˻��� (���ڿ� ���̰� ���� �����Ƿ� ���ǹ��� size() ȣ�� �״�� ��)
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
