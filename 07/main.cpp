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
	
	// ������ ������ res ���ڿ��� ���� 
	for(int i = 0; i < str.size(); i++){
		if(str.at(i) == ' ') continue;
		else res += str.at(i);
	}
	
	// �ҹ��ڷ� ��ȯ�Ͽ� ���
	for(int i = 0; i < res.size(); i++){
		// �빮���� ��� 
		if(res.at(i) >= 'A' && res.at(i) <= 'Z'){
			// �ҹ��ڷ� ��ȯ
			temp = (char) res.at(i) + offset;
			res[i] = temp;
		}
	} 
	
	cout << res;
	
	return 0;
}
