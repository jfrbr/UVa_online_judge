#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,g[100][100],vis[100],a,b;

vector<int> v;

void visit(int u){
	
	vis[u] = 1;
	for (int i=0; i<n;i++){
	   if (g[u][i] && !vis[i]) {
		   visit(i);
	   }
	}
	v.push_back(u);	
}

int main(){

	while ( scanf("%d %d\n",&n,&m) == 2 && (n || m) ){

		memset(g,0,sizeof(g));
		memset(vis,0,sizeof(vis));
		v.clear();

		for (int i=0;i<m;i++){
			scanf("%d %d\n",&a,&b);
			g[--a][--b] = 1;
		}

		for (int i=0;i<n;i++){
			if ( !vis[i] ) {
				visit(i);
			}
		}

		for (int i= v.size()-1 ; i >= 0 ; i--){
			if (i) printf("%d ",v[i]+1);
			else printf("%d\n",v[i]+1);
		}
	}


	return 0;
}
