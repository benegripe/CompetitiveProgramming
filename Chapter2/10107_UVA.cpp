#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>

using namespace std;

int main(void){
	vector<long long int> v;
	long long int n;
	while(scanf("%lld\n",&n) > 0){
		v.push_back(n);
		sort(v.begin(),v.end());
		if (1 == (v.size()%2)){
			int x = ceil(v.size()/2);
			printf("%d\n",v[x]);
		} else {
			int x = floor(v.size()/2);
			int z = floor((v[x] + v[(x-1)])/2);	
			printf("%d\n",z);
		}
	}
}
