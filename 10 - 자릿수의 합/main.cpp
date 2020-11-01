#include <iostream>

using namespace std;

int digit_sum(int x){
	
	int temp = x, cnt = 0;
	int curr, sum = 0;
	while(temp){
		temp /= 10;
		cnt++;
	}
	
	for(int i = 0; i < cnt; i++){
		curr = x % 10;
		sum += curr;
		x /= 10;
	}
	
	return sum;
}

int main(void){
	
	int max = -1, maxNum = -1;
	int n, temp, temp2;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> temp;
		temp2 = digit_sum(temp);
		// ���� ���� ���� ������ ���� digit_sum�� max���� ū ��� 
		if(max < temp2)	{
			max = temp2;
			maxNum = temp;
		}
		// ���� ���� ���� ������ ���� digit_sum�� max�� ���� ��� 
		else if(max == temp2){
			if(maxNum < temp) maxNum = temp;
		} 
	}
	
	cout << maxNum;
	
	return 0;
}
