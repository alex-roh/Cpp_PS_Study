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
		// 해당 날짜의 상담을 하는 경우 - 재귀호출
		if(day + consultList[day].first <= n + 1) {
			DFS(day + consultList[day].first, pay + consultList[day].second);
		}
		// 해당 날짜의 상담을 하지 않는 경우 - 재귀호출 
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
