#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){

int t,a,b,c;

scanf("%d\n",&t);
	for (int i = 1; i <= t; i++){
		scanf("%d %d %d\n",&a,&b,&c);
		printf("Case %d: ",i);
		( (a < b)&&(b < c) || (c < b)&&(b < a) ) ? printf("%d\n",b) : ( (b < a)&&(a < c)|| (c < a)&&(a < b) ) ? printf("%d\n",a) : printf("%d\n",c);
	}
}
