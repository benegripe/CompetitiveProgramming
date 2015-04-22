#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<bitset>


using namespace std;
typedef vector<int> vi;
bitset<1000000> bs;
typedef long long int ll;
vi primes;

int gdc(int x, int y) {return (0 == y)? x: gdc(y,x%y);}

int main(){
	vi in;
	int a,c;	

	while (1){
		scanf(" %d",&a);
		if (0 == a) break;
		in.clear();
		while (0 != a){
			in.push_back(a);
			scanf(" %d",&a);
		}
		if (in.size() > 2){
			c = abs(in[0] - in[1]);
			for (int i = 1; i < in.size(); i++) c = gdc(c,abs(in[0] - in[i]));
		}  
		else c = abs(in[0] - in[1]);
		printf("%d\n",c );
	}
return 0;
}
