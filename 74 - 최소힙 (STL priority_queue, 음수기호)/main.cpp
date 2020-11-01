#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char** argv) {

	// freopen("input.txt", "rt", stdin);

	priority_queue<int> myPriorityQueue;	
	int input;
	cin >> input;
	
	while(input != -1){
		
		if(input == 0){
			cout << -myPriorityQueue.top() << "\n";
			myPriorityQueue.pop();
		}
		else {
			myPriorityQueue.push(-input);
		}
	
		cin >> input;	
	}

	return 0;
}
