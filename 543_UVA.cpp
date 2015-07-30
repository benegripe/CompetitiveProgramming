#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<bitset>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

bitset<1000005> bs;
vi primes;
int A,N;

void sieve(ll N){
	for (ll i = A; i < N+2; i++){
		if (bs[i]){
			for (ll j = i*i; j <= 1000005 ; j+= i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}

int main(){
	ll a,b,l,n1,n2,v;
	
	bs.set();
	primes.clear();
	bs[0] = bs[1] = 0;
	for (ll k = 4; k < 1000005; k+= 2) bs[k] = 0;
	A = 2;
	N = 1;
	while(1){
		scanf("%lld\n",&a);
		if (0 == a) break;
		if (0 == a % 2){ 
			if (N < a) {
				sieve(a);
				A = primes[primes.size()-1];
				N = a;
			}
			l = ceil(primes.size());
			n1 = n2 = -1;
			for (ll i = 0; i < l; i++){
				v = primes.size()-1;
				for (ll j = 0; j <= l; j++)
					if (a == primes[i] + primes[v-j]){
						n1 = primes[i];
						n2 = primes[v-j];
						break;
					} else if (primes[i] + primes[v-j] < a) break;
				if (n1 != -1)break;
			}	
			if ((n1 != -1)&&(n1 != a)&&(n2 != a)) printf("%d = %d + %d\n",a,n1,n2);
			else printf("Goldbach's conjecture is wrong.\n");
		} else printf("Goldbach's conjecture is wrong.\n");
	}
return 0;
}
