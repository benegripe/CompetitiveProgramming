#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){

int t,c,max,n;

scanf("%d\n",&t);
	for (int i = 1; i <= t; i++){
		scanf(" %d ",&n);
		max = -1;
		for (int j = 0; j < n; j++){
			scanf(" %d ",&c);
			max = (max < c) ? c : max;
		}
		printf("Case %d: %d\n",i,max);
	}
}
