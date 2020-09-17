#include <iostream>
#include <stdio.h>

#define MAX 50001

int main(int argc, char** argv) {
	
	int i, j, n;
	int factor[MAX] = {0};
	
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++)
		for(j = i; j <= n; j += i)
			factor[j]++;
			
	for(i = 1; i <=n; i++)
		printf("%d ", factor[i]);
	
	return 0;

}
