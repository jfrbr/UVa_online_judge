#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,dp[1005][1005];
char line[1005];

int main(){

	gets(line);
	n = atoi(line);

	for (int i=0; i < n;i++){
		memset(dp,0,sizeof(dp));		
		gets(line);

		for (int k= strlen(line)-1; k >= 0; k--){
			for (int j=0; j < strlen(line); j++){
				if (k>j){
					dp[k][j]=0;
				}
				else if (k==j){
					dp[k][j]=1;
				}else {
					if ( line[k] == line[j] ){
						dp[k][j] = 2 + dp[k+1][j-1];
					}
					else {
						dp[k][j] = max(dp[k][j-1], dp[k+1][j]);
					}
				}
			}
		}
		printf("%d\n",dp[0][strlen(line)-1]);
	}
	return 0;
}
