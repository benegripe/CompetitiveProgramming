#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int main(void){

int n,b,h,w,cost,beds,sol;

	while (scanf("%d %d %d %d\n",&n,&b,&h,&w) > 0){
		sol = 1 << 30;
		for (int j = 0; j < h; j++){
			scanf("%d\n",&cost);
			for (int i = 0; i < w; i++){
				scanf(" %d ",&beds);
				if ((beds >= n)&&(cost*n <= b)&&(cost*n < sol))
					sol = cost*n;
			}
		}
		if (sol == (1 << 30)) printf("stay home\n");
		else printf("%d\n",sol);
	}
}
