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
	
	/* 두번째 배열에 데이터가 남아있는 경우는 skip 
	   두번째 배열은 arr 배열의 뒷부분에 이미 자리하고 있으므로
	   놔두면 자연스럽게 정렬된 상태로 남기 때문
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
