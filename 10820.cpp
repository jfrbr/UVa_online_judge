#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <algorithm>

#define MAX 50005

using namespace std;

typedef vector<int> vi;

long long a[MAX],p;
vi primes;
long long _sieve_size;
bitset <100000010> bs;

void sieve(long long upperbound){

	_sieve_size = upperbound + 1;
	bs.reset();bs.flip();
	bs.set(0,false); bs.set(1,false);

	for (long long i = 2; i <= _sieve_size; i++){
		if (bs.test((size_t)i)){
			for (long long j = i*i; j<= _sieve_size; j+=i) bs.set( (size_t)j, false ) ;
			primes.push_back((int)i);
		}
	}
}

vi primeFactors(int n){
	
	vi factors;
	int PF_idx=0, PF = primes[PF_idx];
	
	while (n != 1 && (PF * PF <= n) ){
		
		while (n%PF == 0) { n /= PF; factors.push_back(PF);}
		PF = primes[++PF_idx];
	
	}
	if (n != 1) factors.push_back(n);
	
	return factors;
}


int phi(int n){
	
	if (n == 1) return 0;
	
	vi factors = primeFactors(n);
	vi::iterator new_end = unique(factors.begin(), factors.end() );
	
	int result = n;
	
	for (vi::iterator i = factors.begin(); i != new_end; i++){
		result = result - result / *i;
	}
	
	return result;

}

int main(){

	sieve(MAX);
	
	a[0] = 1;
	
	for (int i=1;i<MAX;i++){
		a[i] = a[i-1] + 2 * phi(i);
	}

	while (scanf("%lld\n",&p) && p){
		printf("%lld\n",a[p]);
	}
	
	return 0;
}
