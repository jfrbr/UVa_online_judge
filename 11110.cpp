#include <cstdio>
#include <cstring>

using namespace std;


int n,q[101][101],x,y,color,squares,vis[101][101],fx,fy;
char line[1000],c;
bool s = false;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void imprime(){

	for (int i=0; i<n;i++){
		for (int j=0; j<n;j++){
			printf("%d ",q[i][j]);
		}
		printf("\n");
	}
}

void searchFirst(int color){

	for (int i=0; i<n;i++){
		for (int j=0; j<n;j++){
			if ( q[i][j] == color ){
				fx = i;
				fy = j;
				squares++;
				return;
			}
		}
	}

}

void search (int x,int y,int color){

	if (x < 0 || y < 0 || x >= n || y >= n ) return;

	vis[x][y] = 1;

	int nx,ny;

	for (int i=0;i<4;i++){
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]){
			if ( q[nx][ny] == color ){
				
				squares++;
				search(nx,ny,color);
			}
		}		
	}
}

int main(){


	while (scanf("%d\n",&n),n){
		
		memset(q,0,sizeof(q));
		memset(vis,0,sizeof(vis));

		color = 1;
		s = false;

		for (int i=0; i<n-1;i++){		

			for (;;){
				
				scanf("%d%d%c",&x,&y,&c);
				q[--x][--y]=color;
				if ( c == '\n') break;
			}
		
			color++;
		}
	
		for (int i=0; i<n;i++){
			squares=0;
			searchFirst(i);
			search(fx,fy,i);
			
			if (squares < n || squares > n){
				s = true;
				break;
			}
		}
		
		if (s) printf("wrong\n");
		else printf("good\n");
	}
		
	return 0;
}
