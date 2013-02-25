#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int g[10005][10005],a,b,c,vis[10005],sum,n,best,ff,dfs_num[10005];
char line[15];

int findv(){

	int best_index = -1;
	int max_sum = -1;

	for (int i=0; i < n;i++){
		if ( dfs_num[i] > max_sum){
			max_sum = dfs_num[i];
			best_index = i;
		}
	}
	return best_index;
}
int finds(){

	int max_sum = 0;

	for (int i=0;i<n;i++){
		max_sum = max(max_sum, dfs_num[i]);
	}

	return max_sum;
}

void dfs(int u){

	vis[u] = 1;

	for (int i=0; i < n;i++){
		if (g[u][i] && !vis[i]){
			dfs_num[i]+= g[u][i] + dfs_num[u]; 
			dfs(i);	
		}
	}
}

int main(){

	while (!feof(stdin)){

		memset(g,0,sizeof(g));
//		memset(adj,0,sizeof(adj));

		best = sum = 0;
		n = -1;

		while ( gets(line) && strlen(line) > 0 ){
			sscanf(line,"%d %d %d",&a,&b,&c);
			n = max(n , max(a,b));
			a--;b--;
			g[a][b] = g[b][a] = c;
		//	adj[a][b] = adj[b][a] = 1;
		}
		memset(vis,0,sizeof(vis));
		memset(dfs_num,0,sizeof(dfs_num));
		dfs(0);
		ff = findv();
		memset(dfs_num,0,sizeof(dfs_num));
		memset(vis,0,sizeof(vis));
		dfs(ff);
		best = finds();		
		printf("%d\n",best);
	}

	return 0;
}

