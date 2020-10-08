#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

vector<int> data(15);
vector<bool> visited(15);
int n;
int r;

void DFS(int level, string str){
	
	if(level == r){
		cout << str << "\n";
		return;
	}
	else {
		for(int i = 0; i < n; i++){
			if(visited[i] == false){
				visited[i] = true;
				DFS(level + 1, str + to_string(data[i]) + " ");
				visited[i] = false;
			}
		}
	}
	
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> r;
	for(int i = 0; i < n; i++) cin >> data[i];
	
	DFS(0, "");
	
	return 0;
}
