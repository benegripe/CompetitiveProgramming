#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
int m[103][103];
#define MAX(x,y) ((x < y)?y:x)

int main(){
	int ans,a,n;

	scanf("%d\n",&n);
	int t = n*n;
	for (int i = 0; i < n;i++)
		for (int j = 0; j < n; j++){
			scanf(" %d",&m[i][j]);
			if (i > 0) m[i][j] += m[i-1][j];
			if (j > 0) m[i][j] += m[i][j-1];
			if ((i > 0)&&(j > 0)) m[i][j] -= m[i-1][j-1];
		}
	ans = -127*100*100;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = i; k < n; k++)
				for (int l = j; l < n; l++){
					int aux = m[k][l];
					if (i > 0) aux -= m[i-1][l];
					if (j > 0) aux -= m[k][j-1];
					if ((i > 0)&&(j > 0)) aux += m[i-1][j-1];
					ans = MAX(ans,aux);
				}
	printf("%d\n",ans);
return 0;
}
