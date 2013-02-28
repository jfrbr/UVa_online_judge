#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>

#define INF 1<<20

using namespace std;

int n,m,t,q,g[500][500],adj[500][500],stopover,cost,dist[1500],scenarios=1;

void bellman(){

	dist[0] = 0;

	for (int i=0; i < stopover + 1 ; i++){
		for (int j=n-1; j >= 0; j--){
			for (int k = n-1; k >= 0; k--){
				if (adj[j][k]){
					dist[k] = min (dist[k],dist[j] + g[j][k]);
				}
			}
		}
	}
}
int main(){

	scanf("%d\n",&t);

	while (t--){
		
		scanf("\n%d\n",&n);

		memset(g,0,sizeof(g));
		memset(adj,0,sizeof(adj));

		map<string,int> cities;

		for (int i=0;i<n;i++){
			char city[30];
			scanf("%s\n",city);
			cities[string(city)] = i;
		}

		scanf("%d\n",&m);

		for (int i=0; i<m;i++){
			char c1[30],c2[30];
			scanf("%s %s %d\n",c1,c2,&cost);
			if ( g[cities[string(c1)]][cities[string(c2)]] ) g[cities[c1]][cities[c2]] = min ( g[cities[c1]][cities[c2]],cost );
			else g[cities[string(c1)]][cities[string(c2)]] = cost;
			adj[cities[string(c1)]][cities[string(c2)]] = 1;			
		}	

		printf("Scenario #%d\n",scenarios++);
		
		scanf("%d",&q);		
		
		for (int i=0; i<q;i++){
		
			scanf("%d",&stopover);
			for (int j=0; j < 1000; j++) dist[j] = INF;
			bellman();
			if (dist[n-1] >= INF ) printf("No satisfactory flights\n");
			else printf("Total cost of flight(s) is $%d\n",dist[n-1]);
			
		}
		scanf("\n");
		
		if (t) printf("\n");

	}

	return 0;
}

