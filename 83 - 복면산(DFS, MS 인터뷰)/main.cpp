#include <iostream>
#define S 0
#define E 1 
#define N 2 
#define D 3
#define M 4
#define O 5
#define R 6
#define Y 7
#define n 10

using namespace std;
int arr[n];

int getSend(){
	return arr[S] * 1000 + arr[E] * 100 + arr[N] * 10 + arr[D];
}

int getMore(){
	return arr[M] * 1000 + arr[O] * 100 + arr[R] * 10 + arr[E];
}

int getMoney(){
	return arr[M] * 10000 + arr[O] * 1000 + arr[N] * 100 + arr[E] * 10 + arr[Y];
}

void DFS(int startPos){
	
	if(getSend() + getMore() == getMoney()){
		if(arr[S] == 0 || arr[M] == 0) return;
		printf("  %d %d %d %d\n", arr[S], arr[E], arr[N], arr[D]);
		printf("+ %d %d %d %d\n", arr[M], arr[O], arr[R], arr[E]);
		printf("---------\n");
		printf("%d %d %d %d %d\n", arr[M], arr[O], arr[N], arr[E], arr[Y]);
		return;
	}
	else{
	
		// 0부터 9까지 가능한 순열을 생성 
		for(int i = startPos; i < 10; i++){
			swap(arr[startPos], arr[i]);
			DFS(startPos + 1);
			swap(arr[startPos], arr[i]);
		}	
		
	}
}

int main(int argc, char** argv) {
	
	// 0 1 2 3 4 5 6 7 8 9로 배열 초기화 
	for(int i = 0; i < n; i++) arr[i] = i;
	
	DFS(0);
	
	return 0;
}
