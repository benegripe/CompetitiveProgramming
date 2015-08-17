#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){
	int n,j;
	j = 1;
	while (1){
		scanf("%d\n",&n);
		if (0 == n) break;
		int a,acm;
		acm = 0;
		for (int i = 0; i < n; i++){
			scanf(" %d",&a);
			acm += (0 == a) ? -1 : 1;
		}
		printf("Case %d: %d\n",j,acm);
		j++;
	}
}
