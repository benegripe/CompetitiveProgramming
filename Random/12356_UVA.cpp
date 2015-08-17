#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node {
	int esq;
	int dir;
} ;

node v[100005];

int main(void){
	int n,m,a,b;

	while(scanf("%d %d\n",&n,&m)> 0){
		if ((0 == n)&&(0 == m))break;
		for (int i = 1; i <= n; i++){
			v[i].esq = (i-1);
			v[i].dir = (i+1);
		}
		v[1].esq = 0;
		v[n].dir = 0;
		for (int i = 0; i < m ;i++){
			scanf("%d %d\n",&a,&b);
			v[v[b].dir].esq = v[a].esq;
			v[v[a].esq].dir = v[b].dir;
			if (0 == v[a].esq) printf("*");
			else printf("%d",v[a].esq);
			if (0 == v[b].dir) printf(" *\n");
			else printf(" %d\n",v[b].dir);
		}
		printf("-\n");
	}
}
