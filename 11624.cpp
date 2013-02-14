#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int t,r,c,costs[1005][1005],f_costs[1005][1005],minutes;
char maze[1005][1005];

typedef pair<int,int> ii;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool bound(int x,int y){
	return x >= 0 && x < r && y >= 0 && y < c;
}

void bfs_fire( queue<ii>& fires){

	
	while (!fires.empty()){
	
		int x = fires.front().first;
		int y = fires.front().second;
		fires.pop();

		for (int i=0;i<4;i++){
		
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (bound(nx,ny) ){
				if ( f_costs[x][y] + 1 < f_costs[nx][ny] && (maze[nx][ny] == '.' || maze[nx][ny] == 'J')){
					fires.push(ii(nx,ny));			
					f_costs[nx][ny] = min(f_costs[nx][ny],f_costs[x][y]+1);
				}
			}
		}
	}
}

void bfs_joe( ii& joe){

	costs[joe.first][joe.second] = 0;

	queue<ii> q;

	q.push(joe);

	while (!q.empty()){
	
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i=0;i<4;i++){
			
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (bound (nx,ny)){
				
				if ( maze[nx][ny] == '.' && costs[x][y] + 1 < costs[nx][ny]){
					costs[nx][ny] = costs[x][y] + 1;
					q.push(ii(nx,ny));
				}
			}
		}
	}
	return;
}
void solve(){

	minutes = INF;

	for (int i=0; i < r; i++){
		
		if ( costs[i][0] < f_costs[i][0] ) minutes = min (minutes, costs[i][0]);
		if ( costs[i][c-1] < f_costs[i][c-1]) minutes = min (minutes,costs[i][c-1]);
	
	}

	for (int i=0;i<c;i++){
		
		if ( costs[0][i] < f_costs[0][i] ) minutes = min ( minutes, costs[0][i]);
		if ( costs[r-1][i] < f_costs[r-1][i]  ) minutes = min( minutes,costs[r-1][i]); 
	}

}
int main(){
	
	scanf("%d\n",&t);
	
	while(t--){
	
		memset(maze,0,sizeof(maze));
		memset(costs,INF,sizeof(costs));
		memset(f_costs,INF,sizeof(f_costs));

		ii joe = make_pair(-1,-1);
		ii fire = make_pair (-1,-1);
		
		queue<ii> fires;

		scanf("%d %d\n",&r,&c);
		
		for (int i=0;i<r;i++){	

				gets(maze[i]);

				for (int j=0;j<c;j++){

					if ( maze[i][j] == 'J' ){
						joe = make_pair(i,j);
						costs[i][j] = 0;
					}
					if ( maze[i][j] == 'F' ){
						fire = make_pair(i,j);
						f_costs[i][j] = 0;
						fires.push(fire);
					}
			}
		}
		bfs_joe(joe);
		bfs_fire(fires);

		solve();

		if (minutes < INF) printf("%d\n",++minutes);
		else printf("IMPOSSIBLE\n");
		
	}	
	return 0;
}

