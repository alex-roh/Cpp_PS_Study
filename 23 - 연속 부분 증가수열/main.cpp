#include <iostream>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

template<typename T>
void clear(std::stack<T> &s)
{
   std::stack<T> empty;
   std::swap(s, empty);
}

int main(int argc, char** argv) {
	
	// freopen("in1.txt", "rt", stdin);
	
	// init
	int n, max = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	stack<int> mystack;
	
	for(int i = 0; i < n; i++){
		// top���� ���� �迭�� ���� ���� ��� ���ÿ� �ִ� ���Ҹ� �� 
		if(!mystack.empty() && (mystack.top() > arr[i])){
			// stack.size()�� unsigned integeral type�̹Ƿ� �������� �� �Ұ� 
			if(max < mystack.size()) max = mystack.size();
			while(!mystack.empty()) mystack.pop();
		}
		mystack.push(arr[i]);
	}
	
	cout << max;
	
	return 0;
}
