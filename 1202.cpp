#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <utility>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair <int,int> ii;
typedef pair <int,ii> iii;

int n,m,dist[201][201],ff1,ff2;
bool wall[201][201][4], door[201][201][4];


int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool is_ok(int c_x,int c_y){
    if ( c_x < 0 || c_y < 0 || c_x >= 200 || c_y >= 200) return false;
    return true;
}

void dijkstra(){

    dist[0][0] = 0;

    priority_queue <iii, vector<iii>, greater<iii> > pq;

    pq.push(iii (0, ii(0, 0) ));

    while(!pq.empty()){

        iii top = pq.top();
        pq.pop();

        int d = top.first;
        ii u = top.second;

        if (u.first == ff1 && u.second == ff2) break;        
      
        if (d == dist[u.first][u.second]){
            
                for (int j=0;j<4;j++){

                    int nx = u.first + dx[j];
                    int ny = u.second + dy[j];

                    if ( is_ok(nx,ny) ){
                    
                        if ( !wall[u.first][u.second][j] || door[u.first][u.second][j]){

                            int have_door = door[u.first][u.second][j] > 0 ? 1 : 0;
        
                            if ( dist[u.first][u.second] + have_door < dist[nx][ny]){

                                dist[nx][ny] = dist[u.first][u.second] + have_door;
                                pq.push( iii(dist[nx][ny], ii(nx,ny)));
                            }
                        }
                    }
                }
        }
    }
}

int main(){

    double f1,f2;

    while (scanf("%d %d\n",&m,&n)  == 2){

        if (m == -1 && n == -1) break;

        memset(wall,false,sizeof(wall));
        memset(door,false,sizeof(door));        
        memset(dist,INF,sizeof(dist));

        for (int i=0,x,y,d,t;i<m;i++){
            scanf("%d %d %d %d\n",&x,&y,&d,&t);            
            if (d == 0){
                for (int j=0;j<t;++j){
                    wall[x+j][y-1][0] = true;
                    wall[x+j][y][2] = true;
                }
            }else{
                for (int j=0;j<t;++j){
                    wall[x-1][y+j][1] = true;
                    wall[x][y+j][3] = true;
                }
            }
        }

        for (int i=0,x,y,d;i<n;++i){
        
            scanf("%d %d %d\n",&x,&y,&d);
            if (d==0){
                door[x][y][2] = true;
                door[x][y-1][0] = true;
            }else{
                door[x-1][y][1] = true;
                door[x][y][3] = true;
            }
        }

        scanf("%lf %lf\n",&f1,&f2);

        if (f1 >= 200 || f2 >= 200){
            printf("0\n");
            continue;
        }
                
        ff1 = (int) f1;
        ff2 = (int) f2;

        dijkstra();

        if (dist[ff1][ff2] < INF){
            printf("%d\n",dist[ff1][ff2]);
        }else{
            printf("-1\n");
        }
                              
    }
      
    return 0;
}
