#include<stdio.h>
#include<algorithm>
#include<bitset>
#include<stdlib.h>
#include<vector>
#include<math.h>

using namespace std;
typedef vector<int> vi;
#define MAX 10000003
#define LIM 1000000000000
typedef unsigned long long int ll;
bitset<MAX> bs;
vi primes;
vector<ll> almost;

void sieve(){
	
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= MAX; i++)
		if (bs[i]){
			for (ll j = i*i; j <= MAX; j+= i) bs[j] = 0;
			primes.push_back(i);
		}
}

int main(){
	
	ll n,a,b,count,num,w;
	scanf("%d\n",&n);
	bs.set();
	sieve();
	w = 1;
	for (int v = 0; v < primes.size(); v++){
			count = 0;
			num = primes[v];
			for (int m = 0; m < primes.size(); m++){
				num *= primes[v];
				if (num >= 1)
					if (num <= LIM) almost.push_back(num);
					else break;
			}
	}
	sort(almost.begin(),almost.end());
//	for (int k = 0 ;k < 1000; k++) printf("%d ",almost[k]);

	for (int k = 0; k < n;k++){
		scanf("%lld %lld\n",&a,&b);
 		int beg = lower_bound(almost.begin(),almost.end(),a) - almost.begin() ;
		int end = lower_bound(almost.begin(),almost.end(),b)- almost.begin();
		int res = (end - beg);
		printf("%lld\n",res);
	}

return 0;
}
