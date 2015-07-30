#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

int main(void){
	int k;
	bool b = false;
	vector<int> v;
	while (1){
		scanf(" %d",&k);
		if (0 == k) break;
		if (b) printf("\n");
		b = true;
		v.assign(k,0);
		for (int i = 0;i < k; i++) scanf(" %d",&v[i]);
			sort(v.begin(),v.end());
		for (int i = 0;i < k-5; i++)
			for (int j = i+1; j < k -4; j++)
				for (int l = j+1; l < k-3; l++)
					for (int m = l+1; m < k-2; m++)
						for (int n = m+1; n < k-1; n++)
							for (int o = n+1; o < k; o++)
								printf("%d %d %d %d %d %d\n",v[i],v[j],v[l],v[m],v[n],v[o]);
	}
}
