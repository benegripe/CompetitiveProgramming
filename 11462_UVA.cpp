#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main(void){
	int v[105],a;
	int n; 
	memset(v,0,sizeof(v));
	while(scanf(" %ld\n",&n)> 0){
		if (n == 0)break;
		for (int i = 0; i < n; i++){
			scanf(" %d",&a);
			v[a]++;
		}
		bool f = true;
		for (int i = 1; i < 102; i++){
			if ((v[i] > 0)&&(f)){
				printf("%d",i);
				v[i]--;
				f = false;
			}
			if ((v[i] > 0)&&(!f)) for (int j = 0; j < v[i]; j++) printf(" %d",i);
			v[i] = 0;
		}
		printf("\n");
	}
}
