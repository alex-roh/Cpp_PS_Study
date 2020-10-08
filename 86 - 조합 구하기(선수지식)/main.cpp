#include <iostream>
#include <iterator>

using namespace std;

int n, r;
int combination[100];

void DFS(int startPos, int level)
{
	if(level == r){
		copy(combination, combination + r, ostream_iterator<int>(cout, " "));
		cout << "\n";
		return;
	}
	else {
		for(int i = startPos; i < n; i++){
			combination[level] = i;
			DFS(i + 1, level + 1);
		}
	}
}

int main(int argc, char** argv)
{	
	freopen("input.txt", "rt", stdin);
	cin >> n >> r;
	DFS(0, 0);
	
	return 0;
}
