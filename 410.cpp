#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;


int c,s,v[100],tests=1,cs;
double am,imb;

double abss(double i){
	if ( i < 0 ) return i*-1.0;
	return i;
} 

int main(){

	while ( scanf("%d %d\n",&c,&s) == 2 ){

		memset(v,0,sizeof(v));
		cs=imb=am=0;

		for (int i=0;i<s;i++){
			scanf("%d",&v[i]);
			am+=v[i];
		}
		sort (v , v + s,greater<int>());

		am /= (double) c;
		

		printf("Set #%d\n",tests++);
	
		for (int i=0; i<c;i++){

			if (v[i] != 0 && v[2*c-i-1] == 0){

				printf(" %d: %d\n",i,v[i]);

			}else if (v[i] != 0 && v[2*c-i-1] != 0){

				printf(" %d: %d %d\n",i,v[i],v[2*c-i-1]);

			}else if ( v[i] == 0 && v[2*c-i-1] == 0){

				printf(" %d:\n",i);
			}

			double result = v[i]*1.0 + v[2*c-i-1]*1.0 - am;
			imb += abss(result);
		}
		printf("IMBALANCE = %.5lf\n\n",imb);
		
	}

	return 0;
}
