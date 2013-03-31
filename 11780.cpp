#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define INF 0x3f3f3f

using namespace std;

int n,fib[200],costs[1500],nfib[10000],minimum,quo,res;
double real_costs[1500],err;

int main(){

	memset(fib,0,sizeof(fib));
	memset(costs,0,sizeof(costs));
	memset(nfib,0,sizeof(nfib));
	memset(real_costs,0,sizeof(real_costs));

	for (int i=0;i<1100;i++){
		real_costs[i]=i*1.6;
	}


	fib[0]=0;nfib[0]=1;
	fib[1]=1;nfib[1]=1;


	for (int i=2;i<20;i++){
		fib[i] = fib[i-1] + fib[i-2];
		nfib[fib[i]]=1;
	}

	costs[1] = fib[3];
	costs[2] = fib[4];


	for (int i=3,j=4; i < 1100;i++){

		if (nfib[i]){
			minimum = fib[j+1]; j++;
		}
		else minimum = INF;
	
		err = real_costs[i];

		for (int k=i-1; k>=1; k--){
			quo = i/k;
			res = i%k;
			if (  abs(minimum - err) > abs(quo*costs[k] + costs[res] - err)  ){
				minimum = quo*costs[k] + costs[res];
			}
		}
		costs[i] = minimum;
	}

	while (scanf("%d\n",&n) && n){
		printf("%.2f\n",abs(costs[n]-real_costs[n]));
	}

	return 0;
}
