#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main(void){
	
	string s;
	cin >> s;
	int i = 1;
	while ('*' != s[0]){
		if (0 == s.compare("Hajj")) printf("Case %d: Hajj-e-Akbar\n",i++);
		else printf("Case %d: Hajj-e-Asghar\n",i++);
		cin >> s;
	}
}
