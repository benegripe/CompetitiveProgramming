#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;
typedef vector<int> vi;
vi v,r;

void create(int x){
	v.assign(x+1,0);
	r.assign(x+1,0);
	for (int k = 0; k <= x; k++) v[k] = k;
}

int find(int x){
	return (v[x] == x) ? x : (v[x] = (find(v[x])));
}

bool same(int x, int y){
	return (find(v[x]) == find(v[y]));
}

void uni(int x, int y){
	if (!same(x,y)){
		int a = find(x);
		int b = find(y);
		if (r[a] > r[b]) v[b] = a;
		else { v[a] = b;
			if (r[a] == r[b]) r[y]++;
		}
	}
} 

int main( ){

	int n; scanf("%d\n",&n);
	char c,d;
	bool f = true;;
	int a,b,yes,m,q;
	for (int i = 0; i < n; i++){
		scanf(" %d\n",&m);
		v.clear();
		r.clear();
		create(m);
		if (!f){
			printf("\n");
		} else f = false;
		q = 0;
		yes = 0;
//		printf("%d\n",m);
		while (scanf("%c",&c) > 0){
			if ('\n' == c) break;
			scanf("%d %d%*c",&a,&b);
			//printf("%c %d %d\n",c,a,b);
			if ('c' == c){
				uni(a,b);
			} else { 
				q++;
				yes += (same(a,b))? 1 : 0;
			}
		}
		printf("%d,%d\n",yes,(q-yes));
	}	
return 0;
}
