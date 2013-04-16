#include <cstdio>
#include <cstring>

using namespace std;

int n,cn[12] = {1,1,2,5,14,42,132,429,1430,4862,16796,58786};

int main(){


	scanf("%d\n\n",&n);

	while(true){

		printf("%d\n",cn[n]);

		if (scanf("%d\n\n",&n) == 1){
			printf("\n");
		}else break;
	}

	return 0;
}
