#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>

using namespace std;
typedef vector<int> vi;
vi v,esq,dir;
int n;

void LIS_ESQ(){
	vi lis;
	vi::iterator it;
	lis.assign(n+1,0);
	for (int i = 0; i <= n; i++) lis[i] = (1 << 30);
	lis[0] = -(1 << 30);
	for (int i = 0; i < n; i++){
		it = upper_bound(lis.begin(),lis.end(),v[i]);
		if (0 == (it-lis.begin())) it++;
		if ((*it > v[i])&&(v[i] != lis[(it-lis.begin()-1)])){
			*it = v[i];
			esq[i] = (it -lis.begin());
		} 
	}
}

void LIS_DIR(){
	vi lis;
	vi::iterator it;
	lis.assign(n+1,0);
	for (int i = 0; i <= n; i++) lis[i] = (1<<30);
	lis[0] = -(1<<30);
	for (int i = n-1; i > -1; i--){
		it = upper_bound(lis.begin(),lis.end(),v[i]);
		if (0 == (it - lis.begin())) it++;
		if ((*it > v[i])&&(v[i] != lis[(it-lis.begin()-1)])){
			*it = v[i];
			dir[(n-i)] = (it-lis.begin());
		}
	}
}

int main(void){
	int res,id,val;
	while (scanf("%d\n",&n) > 0){
		v.clear();
		esq.clear();
		dir.clear();
		v.assign(n,0);	
		esq.assign(n+1,0);
		dir.assign(n+1,0);
		for (int i = 0; i < n; i++) scanf(" %d",&v[i]);
		LIS_ESQ();
		LIS_DIR();
		id = 1;
		for (int i = 1; i <= n; i++){
			if ((esq[i] > 0)&&(dir[n-i] > 0))
				if ((id < esq[i]) && (id < dir[n-i])){
					id = (esq[i] < dir[(n-i)])? esq[i] : dir[(n-i)];
				}
		}
		res = 2*(id-1) + 1;
		printf("%d\n",res);
/*
	for (int i = 0; i <= n; i++) printf(" %d",dir[i]);
	printf("\n");
	for (int i = 0; i <= n; i++) printf(" %d",esq[i]);
	printf("\n");
*/
	}
}
