#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int main(void){
	int n,b;
	long long int sum;
	bool sol;
	vector<int> v;
	scanf("%d\n",&n);
	for (int i = 0;i < n; i++){
		int z;
		scanf("%d\n",&z);
		int p;
		scanf("%d\n",&p);
		v.assign(p,0);
		for (int j = 0; j < p; j++) scanf(" %d",&v[j]); 

		sol = false;
		sum = 0;	
		for (long long int k = 0; k < (1 << p) && !sol; k++){
			for (long long int j = 0; j < p ; j++)
				if (k&(1 << j)){
					 sum += v[j];
				}
			if (z == sum) sol = true;
			else sum = 0;
		}
		if (sol) printf("YES\n");
		else printf("NO\n");
	}
}
