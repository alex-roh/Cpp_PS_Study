#include <iostream>

using namespace std;

int target;
bool checks[11];

void printData(){
	
	for(int i = 1; i <= target; i++){
		if(checks[i]) cout << i << " ";
	}
	cout << "\n";
	
}

void traversePreorder(int level){
	
	// base case
	if(level > target){
		printData();
		return;
	}
	else{
		// 포함 & 비포함 여부를 캐싱함 
		checks[level] = true;
		traversePreorder(level + 1);
		checks[level] = false;
		traversePreorder(level + 1);
	}

}

int main(int argc, char** argv) {
	
	cin >> target;	
	traversePreorder(1);
	
	return 0;

}

