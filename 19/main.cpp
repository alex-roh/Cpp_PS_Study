#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	int n, cnt = 0;
	cin >> n;
	
	// 2명 미만의 학생이 들어올 경우 
	if(n < 2) {
		cout << "0\n";
		return 0;
	}
	
	stack<int> maxStack;
	vector<int> heights(n);
	
	for(int i = 0; i < n; i++) cin >> heights[i];

	maxStack.push(heights[n - 1]);
	for(int i = n - 2; i >= 0; i--){
		if(maxStack.top() < heights[i]) 
			maxStack.push(heights[i]);	
	}
	
	cout << maxStack.size() - 1;

	return 0;
}
