#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,p,a,graph[150][150],dfs_count,critical_places,art_points[150],dfs_root;


struct vv{
	int low;
	int num;
	int parent;
	int num_children;
} G[150];
	
void find_art_points(int u){

	G[u].low = G[u].num = dfs_count++;
	
	for (int i=0; i<n;i++){
		if (graph[u][i]){
			if ( G[i].num == -1 ){
	
				G[i].parent = u;
				G[u].num_children++;

				find_art_points(i);

				if (G[i].low >= G[u].num){
					art_points[u] = 1;
				}
				G[u].low = min (G[u].low,G[i].low);

			}else if (G[u].parent != i){
					G[u].low = min (G[u].low,G[i].num);
			}
		}
	}
}

int main(){

	while (scanf ("%d\n",&n) && n){
		
		memset(graph,0,sizeof(graph));
		memset(art_points,0,sizeof(art_points));

		for (int i=0;i<n;i++){
			G[i].low = 0;
			G[i].num_children = 0;
			G[i].num = -1;
			G[i].parent = -1;
		}
	
		for (int i=0; i<n;i++){

			char line[1000], *pch;
			gets(line);

			if (line[0] == '0') break;

			pch = strtok(line," ");
			
			int a = atoi(pch), b; a--;		

			while (1){

				pch = strtok(NULL, " ");
				
				if (pch == NULL) break;
			
				b = atoi(pch);b--;
			
				graph[a][b] = graph[b][a] = 1 ;
			}	
		
		}

		dfs_count = critical_places = 0;
		
		for (int i=0;i<n;i++){
			if ( G[i].num == -1){
				find_art_points(i);
				if (G[i].num_children > 1) art_points[i] = 1;
				else art_points[i] = 0;
			}
		}

		for (int i=1; i<n;i++){
			if (art_points[i]){
				critical_places++;			
			}
		}	
		printf("%d\n",critical_places);
	}
	return 0;
}
