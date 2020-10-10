#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int jungle[21][21];
int simbaRow, simbaCol, simbaSize;
int jungleSize;

struct Bunny {
	int row;
	int col;
	int size;
	Bunny(int r, int c, int s){
		row = r;
		col = c;
		size = s;
	}
	
	bool operator < (const Bunny &b) const {
		
		int myDistance = abs(simbaRow - row) + abs(simbaCol - col);
		int yourDistance = abs(simbaRow - b.row) + abs(simbaCol - b.col);
		
		if(myDistance == yourDistance){
			if(row < b.row) 
				return false;
			else if(row == b.row){
				if(col < b.col)
					return false;
				else 
					return true;
			}
			else
				return true;
		}
		else{
			return myDistance > yourDistance;
		} 
	
	}
	
};

priority_queue<Bunny> bunnies;
priority_queue<Bunny> cantEatBunnies;

int BFS(){
	
	int second = 0; 
	int ateBunnyCnt = 0;
	
	while(!bunnies.empty()){
	
		Bunny closestBunny = bunnies.top();
		bunnies.pop();
		
		// �ɹٰ� �̵��� �� ���ų� �̵��� �ʿ䰡 ���� ���̶�� 
		if(simbaSize <= closestBunny.size){
			cantEatBunnies.push(closestBunny);
			continue;
		}
		
		// �䳢�� �ɹٿ��� �Ÿ� ���
		int distance = abs(simbaRow - closestBunny.row) + abs(simbaCol - closestBunny.col);
		second += distance;
		simbaRow = closestBunny.row;
		simbaCol = closestBunny.col;
		
		cout << "simba(" << simbaSize << ") moved to (" << simbaRow << "," << simbaCol << ")\n";
		
		// �ɹٰ� �䳢�� ��Ƹ��� �� �ִٸ� 
		if(simbaSize > closestBunny.size){
			jungle[simbaRow][simbaCol] = 0;
			ateBunnyCnt++;
			if(ateBunnyCnt == simbaSize){
				simbaSize++;
				ateBunnyCnt = 0;
				// ���� ���ߴ� �䳢���� �ٽ� ť�� ���� 
				while(!cantEatBunnies.empty()){
					bunnies.push(cantEatBunnies.top());
					cantEatBunnies.pop();
				}
			}
		} 
		
		for(int i = 1; i <= jungleSize; i++){
			for(int j = 1; j <= jungleSize; j++){
				cout << jungle[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	return second;
}

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	cin >> jungleSize;
	
	for(int i = 1; i <= jungleSize; i++){
		for(int j = 1; j <= jungleSize; j++){
			cin >> jungle[i][j];
			// �䳢�� ��� 
			if(jungle[i][j] > 0 && jungle[i][j] < 9){
				bunnies.push(Bunny(i, j, jungle[i][j]));
			}
			// �ɹ��� ��� 
			else if(jungle[i][j] == 9){
				simbaRow = i;
				simbaCol = j;
				simbaSize = 2;
				jungle[i][j] = 0;
			}
		}
	}
	
	cout << BFS();
		
	return 0;
}

