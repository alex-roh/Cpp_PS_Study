#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

int m, n;
int minVal = INT_MAX;
pair<int, int> selected[14];
vector<pair<int, int>> houses;
vector<pair<int, int>> pizzaHouses;

void DFS(int startPos, int level){
	
	if(level == m){
		
		int total = 0;
		
		// 선택한 피자집 프린트
		for(int i = 1; i <= m; i++){
			cout << "pizza(" << selected[i].first << "," << selected[i].second << ")\n";
		}
		
		// 총 배달 거리 검사 
		for(int i = 0; i < houses.size(); i++){
			int distFromThisHouse = INT_MAX;
			for(int j = 0; j < m; j++){
				
				int curDist = abs(selected[j].first - houses[i].first) 
							+ abs(selected[j].second - houses[i].second);	
				distFromThisHouse = min(distFromThisHouse, curDist);
			
			}
			total += distFromThisHouse;		
		}
		
		cout << "total = " << total << "\n\n";
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
	
	freopen("input.txt", "rt", stdin);
	
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
	
	DFS(0, 0);
	
	cout << minVal;
	
	return 0;
}
