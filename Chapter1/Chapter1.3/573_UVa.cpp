#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(void){

float h,u,d,f,dist,fat,day;
	
	while(scanf("%f %f %f %f\n",&h,&u,&d,&f) > 0){
			if (0 == u) break;
			f /= 100;
			dist = 0;
			fat = f*u;
			day = 1;
			while (1){
				dist += u;
				if (u > 0) u -= fat;
				if (dist > h) break;
				dist -= d;
				if (dist < 0) break;
				day++;
			}; 
			if (dist > h)
					printf("success on day %1.0f\n",day);
			else 
					printf("failure on day %1.0f\n",day);
	}
}
