#include <iostream>

using namespace std;

int target;
int arr[11];
int total = 0;
bool flag = false;

void DFS(int L, int sum){
	if(flag) return;
	if(L > target){
		cout << "level is " << L << ", sum is " << sum << "\n";
		if(sum == (total - sum)) flag = true;
	}
	else {
		DFS(L + 1, sum + arr[L]);
		DFS(L + 1, sum);
	}	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	int i;
	cin >> target;
	for(int i = 1; i <= target; i++){
		cin >> arr[i];
		total += arr[i];	
	}
	
	DFS(1, 0);
	
	if(flag) cout << "YES";
	else cout << "NO";
	
	return 0;
}
