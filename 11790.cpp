#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t,n,tests=1,dp[20000],dp2[20000],maxinc,maxdec;

struct build{
	int height;
	int width;
} v[100000];

int main(){

	scanf("%d\n",&t);
	while(t--){

		memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));

		maxinc=0;
		maxdec=0;

		scanf("%d\n",&n);

		for (int i=0;i<n;i++){
			scanf("%d",&v[i].height);
		}	
		for (int i=0;i<n;i++){
			scanf("%d",&v[i].width);
		}
		
		maxinc=maxdec=dp[0]=dp2[0]=v[0].width;
		
		for (int i=1;i<n;i++){
			dp[i]=dp2[i]=v[i].width;
			for (int j=0;j<i;j++){
				if ( v[i].height > v[j].height){

					if (dp[i] < dp[j] + v[i].width){
 						dp[i]=dp[j] + v[i].width;
					}
				}
				else if ( v[i].height < v[j].height){

					if (dp2[i]<dp2[j]+v[i].width){
 						dp2[i]=dp2[j]+v[i].width;
					}
				}		
			}
			if(maxinc < dp[i]) maxinc = dp[i];
			if(maxdec < dp2[i]) maxdec = dp2[i];
		}

		if (maxdec > maxinc) printf("Case %d. Decreasing (%d). Increasing (%d).\n",tests++,maxdec,maxinc);
		else printf("Case %d. Increasing (%d). Decreasing (%d).\n",tests++,maxinc,maxdec);
	}

	return 0;
}
