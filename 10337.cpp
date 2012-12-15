#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int n,x,v[15][1500],dp[15][1500];

int main(){

	scanf("%d\n",&n);
	while(n--){

		memset(v,0,sizeof(v));
		memset(dp,INF,sizeof(dp));
	
		scanf("%d\n",&x);
		x /= 100;
	
		for (int i=0;i < 10; i++){
			for (int j=0; j < x; j++){
				scanf("%d",&v[i][j]);
			}
		}

		if ( x == 1){
			printf("%d\n\n",20 - v[9][0]);
	
		}else{

			dp[9][0] = 0;

			for (int j=1;j<x;j++){
				for (int i=8; i>=0;i--){
					if ( i>0 && j>0 && j<x) dp[i][j]=min(dp[i+1][j-1]+60-v[i+1][j-1],min( dp[i][j-1]+30-v[i][j-1], dp[i-1][j-1]+20-v[i-1][j-1] ));
				}
			}

			printf("%d\n\n", dp[8][x-1] + 20 - v[8][x-1]);	
		}

	}

	return 0;
}
