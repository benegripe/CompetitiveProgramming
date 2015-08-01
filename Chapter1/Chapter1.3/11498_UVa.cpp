#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){
	int k;
	long int x,y,dx,dy;

	while (scanf("%d\n",&k) > 0){
		if (0 == k) break;
		scanf("%ld %ld\n",&dx,&dy);
		for (int i = 0; i < k; i++){
			scanf("%ld %ld\n",&x,&y);
			if ((x == dx) || (y == dy))
				printf("divisa\n");
			else {
				if ((x < dx) && (y > dy))
					printf("NO\n");
				else
					if ((x < dx) && (y < dy))
						printf("SO\n");
					else
						if ((x > dx) && (y > dy))
							printf("NE\n");
						else printf("SE\n");
			}
		}
	}
}
