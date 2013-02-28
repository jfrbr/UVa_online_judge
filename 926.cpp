#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int c,n,g[1000][1000],w,px,py,v,vis[1000][1000],xi,xf,yi,yf,vi,vf;
char d;
unsigned long long paths[1000];

void change(){
	
	switch(d){
		case 'N':
			g[v][v+n] = 0;
			break;
		case 'E':
			g[v][v+1] = 0;
			break;
		case 'S':
			g[v-n][v] = 0;
			break;
		case 'W':
			g[v-1][v] = 0;
			break;
	}
}

void bfs (int u){

	queue<int> q;
	q.push(u);
	
	paths[u] = 1;
	
	while (!q.empty()){
		
		int s = q.size();
		
		while (s--){
			
			int topo = q.front();

			q.pop();
			
			for (int i=0; i < n*n; i++){
				if ( g[topo][i] && !vis[topo][i]){
					paths[i] += paths[topo];
					q.push(i);
					vis[topo][i] = 1;
				}
			}
		}
	
	}
}
int main(){

	scanf("%d\n",&c);
	
	while(c--){
	
		memset(g,0,sizeof(g));
		memset(paths,0,sizeof(paths));
		memset(vis,0,sizeof(vis));
		
		scanf("%d\n",&n);
		
		for (int i=0; i < n*n; i++){
			if ( i % n < n-1) g[i][i+1] = 1;
			if ( i + n < n*n) g[i][i+n] = 1;
		}
		scanf("%d %d\n%d %d\n",&xi,&yi,&xf,&yf);
		xi--;yi--;xf--;yf--;
		vi = yi*n + xi;
		vf = yf*n + xf;

		scanf("%d\n",&w);

		for (int i=0; i<w;i++){
			
			scanf("%d %d %c\n",&px,&py,&d);
			px--;py--;
			v = py*n + px;
			change();	
		}

		bfs(vi);

		printf("%llu\n",paths[vf]);	
		
	}

	return 0;
}
