#include<stdio.h>

int main(void){
	int i,n,m,num[1005],t;
	scanf("%d\n",&n);
	t = 1;
	while (0 != n) {
		for (i = 0; i < n; i++)  scanf(" %d",&num[i]);
		int q,k,m,dif,s;
		dif = (1<<26);
		scanf("%d\n",&q);
		printf("Case %d:\n",t++);
		for (i = 1; i <= q; i++){
			scanf("%d\n",&s);
			for (k = 0; k < n; k++)
				for ( m = k + 1; m < n; m++)
					if ( abs(dif-s) > abs(s -(num[k]+num[m]))) dif = (num[k] + num[m]);
			printf("Closest sum to %d is %d.\n",s,dif);	  
		}
		scanf("%d\n",&n);
	}
}
