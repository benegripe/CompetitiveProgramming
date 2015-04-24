#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<set>
using namespace std;
typedef unsigned long long int ll;
typedef vector<char> vc;

int main(){
	vc s;	
	ll n,count,r;
	char c;
	vector<int> rep;
	bool can;

	scanf("%d\n",&n);
	for (int l = 1; l <= n; l++){
		c = getchar();
		s.clear();
		while ('\n' != c){
			s.push_back(c);
			c = getchar();
		}
		sort(s.begin(),s.end());	
		rep.clear();
		for (int i = 0; i < s.size() -1; i++){
			count = 1;
			for (int j = i + 1; j < s.size(); j++) 
				if (s[i] ==  s[j]) count++;
				else break;
			if (1 != count) rep.push_back(count); 
		}
		r = 1;
		can = false;
		for (int k = 2; k <= s.size(); k++){
			for (int j = 0; j < rep.size(); j++)
				if (k == rep[j]){
						can = true;
						rep.erase(rep.begin()+j);
						break;
				} 
			if (can) can = false;
			else r = r*k;
		}
		for (int j = 0; j < rep.size(); j++)
			if (1 != rep[j]) r /= rep[j];
		printf("Data set %d: %lld\n",l,r);
	}
return 0;
}
