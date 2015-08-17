#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<vector>
#include<string.h>

using namespace std;
#define MAX 10005
typedef pair<int, int> ii;
typedef vector<ii> vii;

vii graph[MAX];
int vis[MAX];
int maximo = -1;

int dfs(int u, int sum){
	vis[u] = 1;
	for (int v = 0; v < graph[u].size(); v++){
		if (0 == vis[graph[u][v].first]){
			sum += graph[u][v].second;
			dfs(graph[u][v].first,sum);
			sum -= graph[u][v].second;
		}
	} 
	maximo= (maximo < sum) ? sum : maximo; 
	return sum;
}

int main(){

	int a,b,c,r,m,soma,count;
	set<int> s;
	set<int>::iterator it;
	char in[15];
	bool stop;

	count = 0;
	stop = false;
	while (1){	
		while (1){
			if (gets(in) > 0){
				if ('\0' == in[0]) break;
				count = 0;
				sscanf(in,"%d %d %d",&a,&b,&c);
				graph[a].push_back(make_pair(b,c));
				graph[b].push_back(make_pair(a,c));
				if (s.find(a) == s.end()) s.insert(a);
				if (s.find(b) == s.end()) s.insert(b);
			} else { stop = true;
				 break;
				}
		}
		maximo = -1;
		for (it = s.begin(); it != s.end(); it++){
			soma = 0;
			memset(vis,0,sizeof(vis));
			dfs((*it),soma);
		}
		if (-1 == maximo) maximo = 0;
		printf("%d\n",maximo);
		if (stop) break;
		for (int i = 0; i <= MAX; i++) graph[i].clear();
		s.clear();
	}
return 0;
}
