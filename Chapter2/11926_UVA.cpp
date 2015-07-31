#include<stdio.h>
#include<stdlib.h>
#include<bitset>

using namespace std;

bitset<1000100> calendar;
int n,m,a,b,c;
bool conflits;

bool set_check(){
	int w;
	for (w = a; w < b; w++)
		if (calendar[w]) calendar.flip(w);
		else return true;
	return false;
}

int main(void){
	while(scanf("%d %d\n",&n,&m) > 0){
		if ((0 == n)&&(0 == m)) break;
		conflits = false;	
		calendar.set();

		for (int i = 0; i < n; i++){
			scanf("%d %d\n",&a,&b);
			if (!conflits && set_check()) conflits = true;
		}
		for (int i = 0; i < m; i++){
			scanf("%d %d %d\n",&a,&b,&c);
				while ((a < 1000000)&&(!conflits)){
					conflits = set_check();
					a += c;
					b += c;
				}
						}
		if (conflits) printf("CONFLICT\n");
		else printf("NO CONFLICT\n");
	}
	return 0;
}
