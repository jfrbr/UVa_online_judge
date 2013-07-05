#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int t,n,m,g[205][205],tmp,cases=1,vis[205],total;

int source() {return 0;}
int a_group(int i){ return 1+i;}
int b_group(int i){ return 1+i+n;}
int target() {return 1+n+m;}

int flow_dfs(int s, int t, int minn) {

    vis[s] = 1;

    if (s==t) return minn;
    
    for(int i=0; i<=target(); i++) {
    
        if (!vis[i] && g[s][i] > 0) {
        
            if (int sent = flow_dfs(i, t, min(minn, g[s][i]))) {
                g[s][i] -= sent;
                g[i][s] += sent;
                return sent;
            }
        }
    }
    
    return 0;
}

int main(){

    scanf("%d\n",&t);

    while (t--){

        memset(g,0,sizeof(g));
        
        scanf("%d",&n);

        vector<int> aside;
        vector<int> bside;

        total = 0;
        
        for (int i=0;i<n;i++){
            scanf("%d\n",&tmp);
            aside.push_back(tmp);
            g[source()][a_group(i)] = 1;
        }
        scanf("\n");
        scanf("%d",&m);
        
        for (int i=0;i<m;i++){
            scanf("%d",&tmp);
            bside.push_back(tmp);
            g[b_group(i)][target()] = 1;
        }
        scanf("\n");
        
        for (int i=0;i < (int)bside.size(); i++){
            for (int j=0; j < (int)aside.size(); j++){

                if (aside[j] == 0 && bside[i] == 0){                
                    g [ a_group(j) ] [ b_group(i)] = 1;
                }else if (aside[j] != 0 && bside[i] % aside[j] == 0){
                    g[ a_group(j) ] [ b_group(i) ] = 1;
                }        
            }
        }

        memset(vis,0,sizeof(vis));

        while(int sent = flow_dfs(source(), target(), INT_MAX)) {
            total += sent;
            memset(vis, 0, sizeof(vis));
        }

        printf("Case %d: %d\n",cases++, total);        
    }
    
    return 0;
}
