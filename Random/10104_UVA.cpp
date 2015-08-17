#include<stdio.h>
#include<stdlib.h>

using namespace std;
#define MAX 1000000001
int x,y;
void euc(int a, int b){
	int s = 0 , old_s = 1;
	int t = 1, old_t = 0;
	int r = b, old_r = a;
	int tmp,q;
	while (r){
		q = old_r / r;
		tmp = r;
		r = old_r -q*r;
		old_r = tmp;
		tmp = s;
		s = old_s - q*s;
		old_s = tmp;
		tmp = t;
		t= old_t -q*t;
		old_t = tmp; 
	}
	x = old_s;
	y = old_t;
}

int gdc(int a, int b){ return b == 0 ? a : gdc(b,a%b);}

int main(void){
	int k,l,d;
	while (scanf("%d %d\n",&k,&l)> 0){
		euc(k,l);
		d = gdc(k,l);
		printf("%d %d %d\n",x,y,d);
	}
}
