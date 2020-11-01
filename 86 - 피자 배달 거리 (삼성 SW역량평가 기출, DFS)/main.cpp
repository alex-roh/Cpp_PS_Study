#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

int m, n;
int minVal = INT_MAX;
pair<int, int> selected[20];
vector<pair<int, int>> houses;
vector<pair<int, int>> pizzaHouses;

void DFS(int startPos, int level){
	
	if(level == m + 1){
		
		int total = 0;
		
		// 최소 배달 거리의 총합 구하기 
		for(int i = 1; i < houses.size(); i++){
			int distFromThisHouse = INT_MAX;
			for(int j = 1; j <= m; j++){
				int curDist = abs(selected[j].first - houses[i].first) 
							+ abs(selected[j].second - houses[i].second);	
				distFromThisHouse = min(distFromThisHouse, curDist);
			
			}
			total += distFromThisHouse;
		}
		
		if(total < minVal) minVal = total;
		return;
		
	}
	else {
		
		for(int i = startPos; i < pizzaHouses.size(); i++){
			selected[level] = pizzaHouses[i];
			DFS(i + 1, level + 1);
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	houses.push_back(make_pair(0, 0));
	pizzaHouses.push_back(make_pair(0, 0));
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int val;
			cin >> val;		
			if(val == 1){
				houses.push_back(make_pair(i, j));
			}
			else if(val == 2){
				pizzaHouses.push_back(make_pair(i, j));
			}
		}
	}
	
	DFS(1, 1);
	
	cout << minVal;
	
	return 0;
}
