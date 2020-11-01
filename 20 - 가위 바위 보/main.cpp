#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < n; i++) cin >> B[i];
	
	for(int i = 0; i < n; i++){
		// 비기는 경우 
		if(A[i] == B[i]) cout << "D\n";
		// A가 이기는 경우 
		else if(A[i] == 1 && B[i] == 3) cout << "A\n";	
		else if(A[i] == 2 && B[i] == 1) cout << "A\n";	
		else if(A[i] == 3 && B[i] == 2) cout << "A\n";
		// B가 이기는 경우	
		else cout << "B\n";
	}
	
	return 0;
}
