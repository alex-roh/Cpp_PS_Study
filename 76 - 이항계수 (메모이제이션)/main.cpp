#include <iostream>

using namespace std; 

int table[21][21];

int DFS(int n, int r){
	
	if(n == r) return 1;
	else if(r == 0) return 1;
	else {
	
		if(table[n-1][r-1] == 0) table[n-1][r-1] = DFS(n - 1, r - 1);
		if(table[n-1][r] == 0) table[n-1][r] = DFS(n - 1, r);
		
		return table[n-1][r-1] + table[n-1][r];
	
	}
	
}

int main(int argc, char** argv) {
	
	int n, r;
	cin >> n >> r; // 5, 3
	
	cout << DFS(n, r);
	
	return 0;
}
