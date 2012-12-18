#include <cstdio>
#include <cstring>

using namespace std;


int n,v[100000],sum,media;

int main(){


	while(!feof(stdin)){
	
		memset(v,0,sizeof(v));
		sum=0;
		
		scanf("%d\n",&n);

		for (int i=0;i<n;i++){
			scanf("%d",&v[i]);
			sum += v[i];
		}
		scanf("\n");
		if ( sum%n == 0){
			media = sum/n;
			sum=0;
			for (int i=0; i<n;i++){
				if (v[i] < media ) sum += media-v[i];
			}
			printf("%d\n",sum+1);
		}else{
			printf("-1\n");
		}
		


	}


	return 0;
}
