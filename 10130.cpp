#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t,n,dp[1005][42],v[1005],w[1005],b,s,sum;

int main(){

	scanf("%d\n",&t);
	while(t--){
	
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
		memset(w,0,sizeof(w));
		
		sum=0;
		
		scanf("%d\n",&n);
		for (int i=1;i<=n;++i){
			scanf("%d %d\n",&v[i],&w[i]);
		}
		
		for (int i=0;i<40;++i) dp[0][i]=0;
		
		for (int i=1; i<=n; ++i){
			for (int j=0;j<=40;j++){
				if (j >= w[i]) dp[i][j]=max(dp[i-1][j],  dp[i-1][j-w[i]]  +  v[i]  );
				else dp[i][j] = dp[i-1][j]; 
	
			}
		}
		scanf("%d\n",&b);
		while(b--){
			scanf("%d\n",&s);
			sum+= dp[n][s];
		}
		printf("%d\n",sum);
		
	}
	
	return 0;

}
