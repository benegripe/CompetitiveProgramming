#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;
vector<long int> l,ans;

void LIS(int pos){
	
	MAX(l[pos]+1,LIST(pos+1));




}

int main(void){
	long int a;
	while (scanf("%ld\n",&a) != EOF) {
			l.push_back(a);
	}
	printf("%d\n",int(ans.size()));
	printf("-\n");
	for (int i = 0; i < int(ans.size()); i++)
		printf("%d\n",int(ans[i]));
}
