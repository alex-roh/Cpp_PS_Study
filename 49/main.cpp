#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	
	vector<int> maxForEachColumn(n);
	for(int i = 0; i < n; i++) cin >> maxForEachColumn[i];
	vector<int> maxForEachRow(n);
	for(int i = 0; i < n; i++) cin >> maxForEachRow[i];
	
	
	int cnt;
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j >= 0; j--){
			if(maxForEachColumn[i] <= maxForEachRow[j])
				cnt += maxForEachColumn[i];
			else cnt += maxForEachRow[j];
		}
	}
	
	cout << cnt;
	
	return 0;
}
