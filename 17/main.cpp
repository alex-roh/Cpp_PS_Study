#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	int n, curr, ans;
	int cans; // correct answer
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> curr >> ans;
		cans = curr * (curr + 1) / 2;
		if(ans == cans) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
