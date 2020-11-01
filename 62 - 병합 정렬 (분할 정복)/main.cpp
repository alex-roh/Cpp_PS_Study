#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void merge(int start, int middle, int end, vector<int> &arr){
	
	vector<int> temp(n);
	for(int i = start; i <= end; i++) temp[i] = arr[i];
	
	int s = start;
	int m = middle + 1;
	int pos = start;
	
	while(s <= middle && m <= end)
	{
		if(temp[s] < temp[m])
			arr[pos++] = temp[s++];
		else
			arr[pos++] = temp[m++];
	}
	
	/* �ι�° �迭�� �����Ͱ� �����ִ� ���� skip 
	   �ι�° �迭�� arr �迭�� �޺κп� �̹� �ڸ��ϰ� �����Ƿ�
	   ���θ� �ڿ������� ���ĵ� ���·� ���� ����
	*/
	for(int i = 0; i <= middle - s; i++){
		arr[pos + i] = temp[s + i];
	}
	
}

void mergeSort(int start, int end, vector<int> &arr){
	
	int middle = start + (end - start) / 2;
	
	if(start >= end) {
		return;	
	}
	else {
	
		mergeSort(start, middle, arr);
		mergeSort(middle + 1, end, arr);
		merge(start, middle, end, arr);
		
	}
	
}



int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	mergeSort(0, n - 1, arr);
	
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	
	return 0;
}
