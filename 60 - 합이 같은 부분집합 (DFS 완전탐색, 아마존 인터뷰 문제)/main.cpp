#include <iostream>
#include <vector>

using namespace std;

int target;
int sum = 0;
int total = 0;
int arr[11];
bool yesFlag = false;

void DFS(int level){
	if(yesFlag) return;
	if(level > target){
		if(sum == (total - sum)) yesFlag = true;
		return;
	}
	else{
		
		sum += arr[level];
		DFS(level + 1);
		sum -= arr[level];
		DFS(level + 1);
		
	}
	
}

int main(int argc, char** argv) {
		
	freopen("input.txt", "rt", stdin);	
		
	cin >> target;
	for(int i = 1; i <= target; i++) {
		cin >> arr[i];
		total += arr[i];	
	}
	
	DFS(1);
	
	if(yesFlag) cout << "YES";
	else cout << "NO";
	
	return 0;
}
