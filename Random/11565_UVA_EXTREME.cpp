#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){
	int a,b,c,n;
	bool sol;
	scanf("%d",&n);
	for (int i = 0;i < n; i++){
		sol = false;
		scanf("%d %d %d\n",&a,&b,&c);
		for (int x = -22; x < 23&&!sol; x++)
			if (x*x <= c)
				for (int y = -100; y <= 100&&!sol; y++)
					if ((x !=y )&&(x*x + y*y <= c))
						for (int z = -100; z <= 100&&!sol; z++)
							if ((x != z)&&(z != y)&&(x != y))
								if ((c == x*x + y*y + z*z )&&(b == x*y*z)&&(a == x+y+z)){
									printf("%d %d %d\n",x,y,z);
									sol = true;
								}
		if (!sol) printf("No solution.\n");
	}
}
