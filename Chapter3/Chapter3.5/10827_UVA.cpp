#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
int sec[151][151];

int dp(int c, int r){
	int ans = -100*76*76;
	for(int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			for (int k = i; k < r; k++)
				for (int l = j; l < c; l++){
					int sol = sec[k][l];
					if (i > 0) sol -= sec[i-1][l];	
					if (j > 0) sol -= sec[k][j-1];
					if ( (i > 0)&&(j > 0) ) sol += sec[i-1][j-1];
					if (sol > ans) ans = sol;
				}
	return ans;
}

int main(void){
	int n,t,a;
	scanf("%d\n",&t);
	for (int k = 0; k < t;k++){
		scanf("%d\n",&n);
		memset(sec,0,sizeof(sec));
		for (int i = 0; i < 2*n; i++)
			for (int j = 0; j < 2*n; j++){
					if (i < n && j < n){
						scanf(" %d ",&a);
						sec[i][j] = sec[i+n][j] = sec[i][j+n] = sec[i+n][j+n] = a;
					}
					if (i > 0) sec[i][j] += sec[i-1][j];
					if (j > 0) sec[i][j] += sec[i][j-1];
					if (i > 0 && j > 0) sec[i][j] -= sec[i-1][j-1];
			}
		int s1;
		for (int i = 0; i < 2*n; i++){
			for (int j = 0; j < 2*n; j++)
					printf("%d ",sec[i][j]);
			printf("\n");
		}
		s1 = dp(n,n);
		printf("%d\n",s1);
	}
}
	
