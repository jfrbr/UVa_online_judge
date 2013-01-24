#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <set>
#include <cstring>

using namespace std;

stack<int> dfs_scc;

int x,y,p,t,people,g[1005][1005],ind,in_stk[1005];

struct vv{
	int index;
	int lowlink;
} G[1005];

int tarjanSCC(int u){
	
		G[u].index = ind;
		G[u].lowlink = ind;

		ind++;

		dfs_scc.push(u);
		in_stk[u]=1;
		
		for (int i=0;i<p;i++){

			if (g[u][i] == 1){
				if (G[i].index == -1){
					tarjanSCC(i);
					G[u].lowlink = min( G[u].lowlink, G[i].lowlink );
				}else if (in_stk[i] == 1){
					G[u].lowlink = min ( G[u].lowlink, G[i].index );
				}	
			}
		}

		if ( G[u].lowlink == G[u].index ){

			int last;

		    do {
		        in_stk[ dfs_scc.top() ] = 0;
				last = dfs_scc.top();
				dfs_scc.pop();
		    } while( last != u);
			people++;
		}
}
void zera_stack(){
	while ( !dfs_scc.empty() ) dfs_scc.pop();
}
int main(){

	while (scanf("%d %d\n",&p,&t) == 2){

		if (!p && !t) break;

		map <string,int> m;

		m.clear();
	
		ind=0;

		memset(g,0,sizeof(g));
		memset(in_stk,0,sizeof(in_stk));

		for (int i=0;i<p;i++){
			char line[100];
			gets(line);	
			m[line] = i;
			G[i].index = -1;
		}
		for (int i=0;i<t;i++){
			char line[100],line2[100];
			gets(line);	gets(line2);
			x = m[line];
			y = m[line2];
			g[x][y] = 1;
		}

		people=0;
		zera_stack();

		for (int i=0; i < p;i++){ 
			if ( G[i].index == -1){
				tarjanSCC(i);
			}
		}
		printf("%d\n",people);
	}
	
	return 0;
}
