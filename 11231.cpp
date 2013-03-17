#include <cstdio>

using namespace std;

int n,m,c,a;

int main(){

	while (  scanf("%d %d %d\n",&n,&m,&c) == 3 && (n || m || c) ){
		a = (n-8+1)*(m-8+1);
		printf("%d\n",(a/2) +(a%2)*c);
	}


	return 0;
}
