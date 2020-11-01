#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int n;
int maxPay = INT_MIN;
vector<pair<int, int>> consultList(16);
vector<bool> visited(16);

void DFS(int day, int pay){
	
	if(day == n + 1){
		if(maxPay < pay)
			maxPay = pay;
		return;
	}
	else {
		// �ش� ��¥�� ����� �ϴ� ��� - ���ȣ��
		if(day + consultList[day].first <= n + 1) {
			DFS(day + consultList[day].first, pay + consultList[day].second);
		}
		// �ش� ��¥�� ����� ���� �ʴ� ��� - ���ȣ�� 
		DFS(day + 1, pay); 
	}
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		int startDay, pay;
		cin >> startDay >> pay;
		consultList[i] = make_pair(startDay, pay);
	}
	
	DFS(1, 0);
	cout << maxPay;
	
	return 0;
}
