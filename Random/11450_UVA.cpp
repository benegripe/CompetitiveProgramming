#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>

using namespace std;
#define MAX(x,y) ((x < y)? y: x)

typedef vector<int> vi;
vi fashion[21]; 
int states[201][21];
int money,g;

int opt(int m, int p){
	int aux;
	if (m < 0) return -100000;
	if (p == g) return (money - m);
	if (-1 != states[m][p]) return states[m][p];
	aux = -1;
	for (int v = 0; v < fashion[p].size(); v++)
		aux = MAX(aux,opt(m -fashion[p][v],p+1));
	states[m][p] = aux;
	return states[m][p];
}


int main(){
	int n,t,a,res;

	scanf("%d\n",&n);
	while (n--){
		scanf("%d %d\n",&money,&g);
		for (int k = 0; k < g; k++){
			scanf("%d",&t);
			for (int j = 0 ; j < t; j++){
				scanf(" %d",&a);
				fashion[k].push_back(a);
			}
		}
		memset(states,-1,sizeof(states));
		res = opt(money,0);
		for (int k = 0; k < g; k++) fashion[k].clear();

		if (res > 0) printf("%d\n",res);
		else printf("no solution\n");

	}
return 0;
}
