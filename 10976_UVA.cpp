#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<vector>

using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vi;

int main(void){
	int n;
	vi sol;
	while (scanf("%d\n",&n) > 0){
		for (int i = n+1; i <= 20000; i++) 
			if (0 ==  ((i*n)%(i-n))){
				int a = i;
				int b = (i*n)/(i-n);
				if (b >= a) sol.push_back(make_pair(b,a)); 
			}
		int c = sol.size();
		int d = n;
		printf("%d\n",c);
		for (int i = 0;i < sol.size(); i++) printf("1/%d = 1/%d + 1/%d\n",d,sol[i].first,sol[i].second);
		sol.clear();
	}
}
