#include<stdio.h>
#include<stdlib.h>

int main(void){
	
	unsigned long long int k,a,b,x,i,w,j;
	int turn;
	x = 1;
	while(scanf("%llu\n",&k) > 0){
		a = b = j = turn = 0;
		if (0 == k) break;
		for (i = k; i != 0;){ 
			w = i;
			i = i&(i-1);
			w -= i;
			if (w){
				if (!turn){
					a += w;
					turn = 1;
				} else {
					b += w;
					turn = 0;
				}
			}
		}
		printf("%llu %llu\n",a,b);
	}
return 0;
}

