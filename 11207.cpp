#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,w,h,best_index;
double best_square,square,menor_lado,maior_lado;

int main(){

	while ( scanf("%d\n",&n) && n){

		best_index = -1;
		best_square = -1;

		for (int i=0; i < n;i++){

			scanf("%d %d\n",&w,&h);

			if (w < h){
				menor_lado = (double)w;
				maior_lado = (double)h;
			}else{
				menor_lado = (double)h;
				maior_lado = (double)w;
			}
	
			if (maior_lado == menor_lado){
				square = maior_lado*maior_lado/4.0;
			}else if (maior_lado >= (4*menor_lado)){
				square = menor_lado*menor_lado;
			}else{
				square = max(maior_lado*maior_lado/16.0, menor_lado*menor_lado/4.0);
			}

			
			if (square > best_square){
				best_square = square;
				best_index = i;
			}

		}
		printf("%d\n",best_index+1);		
	
	}


	return 0;
}
