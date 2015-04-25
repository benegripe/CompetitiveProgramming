#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>

using namespace std;
typedef vector<char> vc;
vc s1,s2;
char in[1005];
int mem[1005][1005];
#define MAX(x,y) ((x < y) ? y : x)

int opt(int a, int b){

	int sol,sol1;
	sol = sol1 = 0;
	if ( (a > s1.size()-2) ||(b > s2.size()-2)) return 0;
	if ( -1 != mem[a][b]) return mem[a][b];
	else {
			if (s1[a] == s2[b])
				sol1 = 1 + opt(a+1,b+1);
			else sol = MAX(opt(a+1,b),opt(a,b+1));
			sol = MAX(sol,sol1);
			
	}
	mem[a][b] = sol;
	return sol;
}					

int main(){
	char ci;

	while (scanf("%c",&ci) != EOF){
		s1.clear();
		s2.clear();
		memset(mem,-1,sizeof mem);
		s1.push_back(ci);
		while ('\n'!= ci){
			scanf("%c",&ci);
			s1.push_back(ci);
		}
		ci = 'a';
		while ('\n' != ci){
			scanf("%c",&ci);
			s2.push_back(ci);
		}
//		for (int i = 0; i < s1.size(); i++) printf("%c",s1[i]);
//		for (int i = 0; i < s2.size(); i++) printf("%c",s2[i]);
		int res = opt(0,0);
		printf("%d\n",res);
		
	}

return 0;
}
