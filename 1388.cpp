#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n,m;
double pos, ans;
double new_i;

int main(){
	while(scanf("%d %d\n",&n,&m) == 2){
	
		ans = 0;
		
		for (int i=1; i <n;++i){
			pos = (i*1.0)/n * (n+m);
			ans += fabs(pos - ceil(pos - 0.5))/(n+m);
		}
		
		printf("%.4lf\n",ans*10000);
	}
	return 0;
}
