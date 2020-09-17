#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	int n = 10;
	int aS = 0, bS = 0; // A score and B score
	int lastWin = 0; // 0 - Draw, 1 - A, 2 - B
	vector<int> A(n);
	vector<int> B(n);
	
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < n; i++) cin >> B[i];

	for(int i = 0; i < n; i++){
		if(A[i] == B[i]){
			aS++; bS++;
		}	
		else if(A[i] > B[i]){
			aS += 3; lastWin = 1;
		}
		else {
			bS += 3; lastWin = 2;
		}
	}
	
	// 점수 출력 
	cout << aS << " " << bS << "\n";
	
	// 승자 출력
	if(aS == bS && lastWin == 0) cout << "D\n";
	else if((aS == bS && lastWin == 1) || (aS > bS)) cout << "A\n";
	else cout << "B\n"; 
	
	return 0;
}
