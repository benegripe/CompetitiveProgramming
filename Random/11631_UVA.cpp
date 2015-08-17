#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
viii v;
vector<int> u,r;

void create(int x){
	u.assign(x,0);
	for (int i = 0; i < x; i++) u[i] = i;
}

int find(int x){
	return ((u[x] == x) ? x : (u[x] = find(u[x])));
}

bool same(int x, int y){
	return (find(x) == find(y));
}

void uni(int x, int y){
	if (!(same(x,y))){
		int z = find(y);
		int w = find(x);
		if (r[z] < r[w]) u[z] = w;
		else { u[w] = z;
		       if (r[z] == r[w]) r[z]++;
		}
	}
}

bool cmp(iii s, iii r){
	return (s.first < r.first) ? true : false;
}


int main(void){
	int n,m,a,b,c,sum,val;
		
	while(scanf("%d %d\n",&m,&n) > 0){
		if ((0 == m)&&(0 == n)) break;	
		v.clear();
		u.clear();
		r.clear();
		r.assign(m,0);
		create(m);
		sum = 0;
		val = 0;
		for (int i = 0; i < n; i++){
			scanf("%d %d %d\n",&a,&b,&c);
			v.push_back(make_pair(c,make_pair(a,b)));
			sum += c;
		}
		sort(v.begin(),v.end(),cmp);		
		for (int i = 0; i < n; i++)
			if (!same(u[v[i].second.first],u[v[i].second.second])){
				uni(v[i].second.first,v[i].second.second);
				val += v[i].first;	
			}
		printf("%d\n",(sum-val));
	}
}
