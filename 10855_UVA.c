#include<stdio.h>
#include<stdlib.h>

int N,n;
char big[1000][1000],small[4][1000][1000];

int recognize(int row,int col,int rot){
	int i,j,k,m;

	if ( ((N - row) < n) || (N-col) < n) 
		return 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++){
			if (small[rot][i][j] != big[row+i][col+j])
				return 0;
		}

	return 1;
}

int main(void){

	int a,b;
	while(scanf("%d %d\n",&N,&n) > 0){
		if ((0 == N)&&(0 == n)) break;

		int sol[4] = {0,0,0,0};

		for (a = 0; a < N; a++)
			for (b = 0; b < N; b++)
				scanf(" %c",&big[a][b]);

		for (a = 0; a < n; a++)
			for (b = 0; b < n; b++)
				scanf(" %c",&small[0][a][b]);

		for (a = 0; a < n; a++)
			for (b = 0; b < n; b++)
				small[1][b][n-a-1] = small[0][a][b];

		for (a = 0; a < n; a++)
			for (b = 0; b < n; b++)
				small[2][b][n-a-1] = small[1][a][b];

		for (a = 0; a < n; a++)
			for (b = 0; b < n; b++)
				small[3][b][n-a-1] = small[2][a][b];

		for (a = 0; a < N; a++)
			for (b = 0; b < N; b++){
				if (big[a][b] == small[0][0][0])
					sol[0] += recognize(a,b,0);
				if (big[a][b] == small[1][0][0])
					sol[1] += recognize(a,b,1);
				if (big[a][b] == small[2][0][0])
					sol[2] += recognize(a,b,2);
				if (big[a][b] == small[3][0][0])
					sol[3] += recognize(a,b,3);
			}	
		printf("%d %d %d %d\n",sol[0],sol[1],sol[2],sol[3]);
	}
	return 0;
}

