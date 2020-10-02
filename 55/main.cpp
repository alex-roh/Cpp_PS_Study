#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	stack<int> mystack;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	
	string res = "";
	int toBePushed = 1;
	for(int i = 1; i <= n; i++){

		// check possibility
		if(!mystack.empty() && mystack.top() < arr[i]){
			cout << "impossible";
			return 0;
		}

		mystack.push(arr[i]);
		res += 'P';
		
		while(!mystack.empty() && mystack.top() == toBePushed){
			res += 'O';
			toBePushed++;
			mystack.pop();
		}
	}
	
	if(!mystack.empty()) {
		cout << "impossible";
		return 0;
	}
	
	cout << res;
	
	return 0;
}
