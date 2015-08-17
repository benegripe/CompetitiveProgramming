#include<stdio.h>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int ll;
typedef vector<int> vi;

int gdc(int a, int b) {return (0 == b)? a: gdc(b,a%b);}

int main(){
	int n,max,r,d,k,v;
	char c[1003], *p;
	int in[103];

	scanf("%d\n",&n);
	for (int i =0 ; i < n; i++){
		cin.getline(c,1000);
		p = c;
		r = 0;
		while( sscanf(p,"%d%n",&in[r++],&k) != EOF) p+= k;
		max = 1;
		r--;
		for (int m = 0; m < r ; m++)
			for (int j = m +1; j < r; j++){
				v = gdc(in[m],in[j]);
				max = (max < v)? v : max;

			}
		printf("%d\n",max);
	}
return 0;
}
