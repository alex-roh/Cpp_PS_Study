#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	// init
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> res(n, 1);
	deque<int> mydeque;
	for(int i = 0; i < n; i++) cin >> arr[i]; 
	
	for(int i = 0; i < n; i++){
		
		if(mydeque.empty())
			mydeque.push_front(arr[i]);
		
		else if(mydeque.front() >= arr[i]){
			res[i] += mydeque.size();
			mydeque.push_front(arr[i]);
		}
			
		else if(mydeque.back() >= arr[i]){
			int cnt = 0;
			deque<int>::iterator it = mydeque.end(); it--;
			while(*it >= arr[i]) {
				it--; cnt++;
			}
			it = mydeque.insert(++it, arr[i]);
			res[i] += cnt;
		}
		
		else mydeque.push_back(arr[i]);
		
	}
	
	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
		
	return 0;
}
