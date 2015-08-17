#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>

#define PI acos(-1)

using namespace std;

int main(void){
	double l,w,h,theta;

	while (scanf("%lf %lf %lf %lf\n",&l,&w,&h,&theta) > 0){
		double h1 = sin(theta*PI/180)*l;
		double b1 = l/cos(theta*PI/180);
		double vt = ((b1*h1)/2)*w;
		double v = h*w*l;
		if (vt > (v/2)){
			double x = 90 -theta;
			h1 = sin(x*PI/180)*h;
			b1 = h/cos(x*PI/180);
			v = ((b1*h1)/2)*w;
		} else { v -= vt;}
		printf("%.3lf mL\n",v);
	}
}
