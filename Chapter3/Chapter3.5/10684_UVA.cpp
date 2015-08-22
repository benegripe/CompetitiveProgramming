#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){
	long long int n, acm,i,m,sol;
	while (scanf("%lld\n",&n),n){
		acm = 0;
		sol = -(1 << 20);
		for (i = 0; i < n; i++){
			scanf(" %lld ",&m);
			acm += m;
			if (sol < acm)
				sol = acm;
			if (acm < 0)
				acm = 0;
		}
		if (sol > 0)
			printf("The maximum winning streak is %lld.\n",sol);
		else
			printf("Losing streak.\n");
	}
}
