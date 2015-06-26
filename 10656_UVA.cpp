#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>

using namespace std;
typedef vector<int> vi;

int main(){
	int n,a,count;
	bool pri;

	while (1){
		scanf("%d\n",&n);
		pri = false;
		count = 0;
		if (0 == n) break;
		for (int i = 0; i < n; i++){
			scanf("%d\n",&a);
				if (0 != a)
					if (!pri){
						printf("%d",a);
						pri = true;
					} else printf(" %d",a);
				else count++;
			}
			if (count == n) printf("0");
		printf("\n");
	}	
return 0;
}
