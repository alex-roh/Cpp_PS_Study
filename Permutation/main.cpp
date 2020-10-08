#include <iostream>
#include <iterator>

using namespace std;

char data[4] = {'a', 'b', 'c', 'd'};
int n = 4;
static int debug = 1;

void perm(int k){
	if (k == n){
		copy(data, data + 4, ostream_iterator<char>(cout, " "));
		cout << "\n";
		return;
	}
	
	for(int i = k; i < n; i++){
		swap(data[k], data[i]);
		// k까지는 고정되었다고 가정하고 k + 1을 호출 
		perm(k + 1);
		/* 재귀 호출이 끝나면 스왑했던 k와 i를 다시 되돌려야
		   재귀 이전과 이후의 데이터의 동일성이 유지된다. */
		swap(data[k], data[i]); 
	}
	
}

int main(){
	
	perm(0);
	
	return 0;
	
}

