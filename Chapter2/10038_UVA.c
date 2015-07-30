#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int n,i,a,b;
	while (scanf("%d ",&n) > 0){
		int jolly[3000] = { 0 };
		if (n > 0)
			scanf("%d ",&a);
		for (i = 1; i < n; i++){
			scanf("%d ",&b);
			jolly[abs(a-b)] = 1;
			a = b;
		}
		for (i = 1; i < n && jolly[i];i++);

		if (i == n && 0 != n) printf("Jolly\n");
		else printf("Not jolly\n");
	}
return 0;
}
