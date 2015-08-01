#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){

int n;
long long int a,b;
	scanf("%d\n",&n);
	for (int i = 0; i < n; i++){
		scanf("%lld %lld\n",&a,&b);
		(a > b) ? printf(">\n") : (a < b) ? printf("<\n") : printf("=\n") ;
	}
}
