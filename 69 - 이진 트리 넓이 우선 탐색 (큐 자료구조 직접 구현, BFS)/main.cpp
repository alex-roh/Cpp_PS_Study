#include <iostream>
#include <queue>
#include <vector>
#define n 7

using namespace std;

vector<int> tree[n];
bool visit[n];

void BFS(int startLevel){

	queue<int> myqueue;
	myqueue.push(startLevel);
	while(!myqueue.empty()){
		int node = myqueue.front();
		myqueue.pop();
		cout << node << " ";
		for(int i = 0; i < tree[node].size(); i++){
			myqueue.push(tree[node][i]);
		}
	}
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	for(int i = 1; i < n; i++){
		int source, dest;
		cin >> source >> dest;
		tree[source].push_back(dest);
	}

	BFS(1);
	
	return 0;
}
