#include <cstdio>
#include <cstring>

using namespace std;


unsigned long long value,dp[30001], coins[5] = {1,5,10,25,50}, numCoins=5, coinValue;

int main(){

	while(!feof(stdin)){
		
		memset(dp,0,sizeof(dp));
		scanf("%llu\n",&value);
	
		dp[0] = 1;
		
		for (int i=0; i < numCoins;i++){
			coinValue = coins[i];
		
			for (int j=coinValue; j<= value; j++){
				dp[j] += dp [j-coinValue];
			}
		}
		if ( dp[value] > 1) printf("There are %llu ways to produce %llu cents change.\n", dp[value], value);
		else printf("There is only 1 way to produce %llu cents change.\n", value);
		
	}	


	return 0;
}
