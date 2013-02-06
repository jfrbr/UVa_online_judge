#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

int t,m,n,g[1005][1005],dist[1005][1005];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

typedef pair<int,int> ii;
typedef pair<int,ii> iii;


void imprime(){

	for (int i=0;i<n;i++){
	
		for (int j=0;j<m;j++){
			printf("%03d ",dist[i][j]);
		}
		printf("\n");
	}

}

void dijkstra(){

	dist[0][0]=g[0][0];

	priority_queue<iii, vector<iii>, greater<iii> > q;

	iii p = make_pair(g[0][0],ii(0,0));

	q.push(p);
	
	while (!q.empty()){
	
		iii top = q.top(); q.pop();
		int cost = top.first;
		ii pos = top.second;
		
		if ( dist[pos.first][pos.second] == cost)
			for (int i=0; i<4;i++){
				int nx = pos.first + dx[i];
				int ny = pos.second + dy[i];

				if (nx >= 0 && nx < n && ny>=0 && ny < m){
			
					if ( dist[pos.first][pos.second] + g[nx][ny] < dist[nx][ny]){

						dist[nx][ny] = dist[pos.first][pos.second] + g[nx][ny];
						iii next = make_pair(dist[nx][ny],ii(nx,ny));
	
						q.push(next);
					}
				}
			}
	}
}

int main(){

	scanf("%d\n",&t);
	while (t--){
	
		memset(g,0,sizeof(g));
		memset(dist,INF,sizeof(dist));


		scanf("%d\n%d\n",&n,&m);

		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				scanf("%d ",&g[i][j]);
			}
			scanf("\n");
		}
	
		dijkstra();

		printf("%d\n",dist[n-1][m-1]);
	
	}

	return 0;
}
