#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int n, factor;
	cin >> n;
	vector<int> res(n + 1);
	
	// �� 2 ~ n���� 
	for(int i = 2; i <= n; i++){
		int num = i;
		// ���μ����� 
		factor = 2;
		while(true){
			// ���� factor�� �μ����ذ� �����ϸ� ������ ������ ���� 
			if(num % factor == 0){
				res[factor]++;
				num /= factor;
			}
			else factor++; // �Ұ����ϸ� factor�� 1 ������Ŵ 
			// num�� 1�� �Ǹ� ���μ����ذ� ���� ���̹Ƿ� �������� 
			if(num == 1) break;
		}
	}
	
	cout << n << "! = ";
	for(int i = 2; i <= n; i++){
		if(res[i] != 0) cout << res[i] << " ";
	}
			
	return 0;
}
