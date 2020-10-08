#include <iostream>
#include <vector>
#include <limits>

#define PLUS 1
#define MINUS 2
#define MULT 3
#define DIV 4

using namespace std;

int n;
int minVal = INT_MAX;
int maxVal = INT_MIN;

vector<int> sequence(12);
vector<int> operators(5);

void DFS(int pos, int sum){
	
	if(pos == n){
		if(sum < minVal) minVal = sum;
		if(sum > maxVal) maxVal = sum;
		return;
	}
	else {
		if(operators[PLUS] > 0){
			operators[PLUS]--;
			DFS(pos + 1, sum + sequence[pos + 1]);
			operators[PLUS]++;
		}
		if(operators[MINUS] > 0){
			operators[MINUS]--;
			DFS(pos + 1, sum - sequence[pos + 1]);
			operators[MINUS]++;
		}
		if(operators[MULT] > 0){
			operators[MULT]--;
			DFS(pos + 1, sum * sequence[pos + 1]);
			operators[MULT]++;
		}
		if(operators[DIV] > 0){
			operators[DIV]--;
			DFS(pos + 1, sum / sequence[pos + 1]);
			operators[DIV]++;
		}
		
	}
	
}

int main(int argc, char** argv) {
	
	// freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		sequence[i] = num;
	}
	cin >> operators[PLUS];
	cin >> operators[MINUS];
	cin >> operators[MULT];
	cin >> operators[DIV];
	
	// 첫번째 값은 계산되지 않으므로 sum = sequence[1]로 초기화 
	DFS(1, sequence[1]);
	
	cout << maxVal << "\n" << minVal;
	
	return 0;
}
