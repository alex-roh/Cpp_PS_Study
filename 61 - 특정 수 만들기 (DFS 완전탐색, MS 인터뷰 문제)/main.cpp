#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
int target;
int arr[11], path[11];
int sum = 0;
int res = 0;

void DFS(int level){
	
	if(level > n){
		// base case	
		if(sum == target){
			res++;
		}
	} 
	else {
		
		sum += arr[level]; // ���� �� ���� 
		DFS(level + 1);
		
		sum = sum - arr[level] - arr[level]; // ���� �� ���̳ʽ� 
		DFS(level + 1); 
		
		sum += arr[level]; // ���� �� ��ŵ 
		DFS(level + 1);
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	cin >> n >> target;
	for(int i = 1; i <= n; i++) cin >> arr[i];	
	
	DFS(1);
	
	if(res == 0) cout << "-1";
	else cout << res;
	
	return 0;
	
}
