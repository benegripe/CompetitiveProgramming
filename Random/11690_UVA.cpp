#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>

using namespace std;

typedef vector<int> vi;
vi g,v;


void set_create(int n){
	g.assign(n,0);
	for (int i = 0; i < n; i++) g[i] = i;
}

int fetch_father(int a){
	return (a == g[a])? a : (g[a] = fetch_father(g[a]));
}

int same_set(int a, int b){
	return (fetch_father(g[a]) == fetch_father(g[b]));
}

void union_set(int a, int b ){
	g[fetch_father(a)] = fetch_father(g[b]);
}

int main(){

	int t,c,a,b,n_v;
	bool r;

	scanf("%d\n",&t);
	for (int i = 0; i < t; i++){
		scanf("%d %d\n",&n_v,&c);
		v.assign(n_v,0);
		set_create(n_v);
		for(int j = 0; j < n_v; j++) scanf("%d\n",&v[j]);

		for(int j = 0; j < c; j++){
			scanf("%d %d\n",&a,&b);
			union_set(a,b);
			if (a != fetch_father(a)){
				 v[fetch_father(a)] += v[a];
				 v[a] = 0;
			}
			if (b != fetch_father(b)){
				v[fetch_father(b)] += v[b];
				v[b] = 0;
			}
		}
		for (int j = 0; j < g.size(); j++)
			if (0 != v[j])
				if (j != g[j]){
					v[fetch_father(j)] += v[j];
					v[j] = 0;
				}

		r = true;
		for (int j = 0; j < n_v; j++) 
			if (0 != v[j]){
				r = false;
				break;
			}
		printf((r)? "POSSIBLE\n":"IMPOSSIBLE\n");
		g.clear();
		v.clear();
	}
return 0;
}
