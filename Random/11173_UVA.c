#include<stdio.h>
#include<stdlib.h>

int main(void){
	unsigned int m,n,j,k,g;
	scanf("%d\n",&m);
	for (j = 0; j < m; j++){
		scanf("%u %u\n",&n,&k);
		g = (k >> 1)^k;
		printf("%d\n",g);
	}
	return 0;
}
