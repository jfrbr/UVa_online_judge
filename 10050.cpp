#include <cstdio>
#include <cstring>


int main(){

	int t,n,p,res;
	int days[4000];
	int pp;

	scanf ("%d\n",&t);
	while (t--){
		res=0;
		scanf("%d\n",&n);
		memset(days,0,sizeof(days));

		scanf("%d\n",&p);
		for (int i=0;i<p;i++){
			scanf("%d\n",&pp);
			for (int j=1;j*pp <= n;j++) {
				int d = j*pp;
				if (!days[d]) {
					days[d] = 1;
					if ( d%7 != 6 && d%7 != 0){
						res++;
					}
				}
			}
		}

		printf("%d\n",res);
	
	}


	return 0;
}
