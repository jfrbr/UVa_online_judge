#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int m[501][501];
int w,h,n;

void print(){

	for (int i=1;i<=w;i++){
        printf("%d - ", i);
		for(int j=1;j<=h;j++){
			printf("%d", m[i][j]);
		}
		printf("\n");
	}
}

int main(){

	int x1,y1,x2,y2;
	int xminimo,xmaximo;
	int yminimo, ymaximo;
	int resultado;
	
	while ( scanf("%d %d %d\n",&w,&h,&n)){

        if (!w && !h && !n) break;

		memset(m,0,sizeof(m));
		resultado=0;

		while (n--){
			scanf("%d %d %d %d\n",&x1,&y1,&x2,&y2);
		
			xminimo = min(x1,x2);
			xmaximo = max(x1,x2);

			yminimo = min(y1,y2);
			ymaximo = max(y1,y2);


			for (int i=yminimo; i<=ymaximo; i++){
				for (int j=xminimo; j<=xmaximo;j++){
					m[i][j]=1;
				}
			}
		}

		for (int i=1;i<=h;i++){
			for (int j=1;j<=w;j++){
					if (!m[i][j]) resultado++;
				}
		}

		if (resultado == 0){
			printf("There is no empty spots.\n");
		} else if (resultado == 1){
			printf("There is one empty spot.\n");
		} else {
			printf("There are %d empty spots.\n", resultado);
		}
		
		scanf("\n");
	}

	return 0;
}
