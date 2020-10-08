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
		// k������ �����Ǿ��ٰ� �����ϰ� k + 1�� ȣ�� 
		perm(k + 1);
		/* ��� ȣ���� ������ �����ߴ� k�� i�� �ٽ� �ǵ�����
		   ��� ������ ������ �������� ���ϼ��� �����ȴ�. */
		swap(data[k], data[i]); 
	}
	
}

int main(){
	
	perm(0);
	
	return 0;
	
}

