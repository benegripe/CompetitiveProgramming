#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){
	int n,a,b,c;
	bool sol;
	scanf("%d\n",&n);
	for (int i = 0;i < n; i++){
		scanf("%d %d %d\n",&a,&b,&c);
		sol = false;
		for (int x = -101; x < 102; x++)
			for (int y = -101; y < 102; y++)
				for (int z = -101; z < 102; z++) 
					if ((x != y)&&(y != z)&&(z != x)){
						if ((c == (x*x + y*y + z*z))&&(b == (x*y*z))&&(a == (x+y+z))&&(!sol)) {
							sol = true; 
							printf("%d %d %d\n",x,y,z);	
						}
					}
		if (!sol) printf("No solution.\n");
	}
}
