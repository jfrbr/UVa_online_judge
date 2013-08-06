#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

#define pb push_back

using namespace std;

typedef pair<int,int> ii;

class UnionFind{

    private:
        int p[10500], rank[10500];
    public:
        UnionFind(int N) {
            memset(p,0,sizeof(p));;
            memset(rank,0,sizeof(rank));
            
            for (int i=0; i < N; ++i){
                p[i] = i;
            }
        }
        int findSet(int i){ 
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j){ 
            return findSet(i) == findSet(j);
        }
        void unionSet(int i,int j){
        
            if (!isSameSet(i,j)){
            
                int x = findSet(i);
                int y = findSet(j);
                
                if (rank[x] > rank[y]){
                    p[y] = x; 
                }else{
                    p[x] = y;
                    if (rank[x] == rank[y]) rank[y]++;
                }
            }
        }

};

int c,n,m,j1,j2,cost,total;

int main(){

    scanf("%d\n",&c);
    
    while (c--){

        scanf("%d %d\n",&n,&m);
        vector< pair <int ,ii> > EdgeList;
        total = 0;
        
        for (int i=0; i < m; ++i){
            scanf("%d %d %d\n",&j1,&j2,&cost);
            EdgeList.pb( make_pair(cost,ii(j1,j2) ));
            total += cost;
        }

        sort(EdgeList.begin(), EdgeList.end() , greater< pair<int, ii> >() );

        int mnt_cost = 0;

        UnionFind UF(n);

        for (int i=0; i < m;++i){

            pair <int ,ii > front = EdgeList[i];

            if (!UF.isSameSet(front.second.first, front.second.second)){
                mnt_cost += front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
    
        }

        printf("%d\n",total-mnt_cost);
        

    }

    return 0;
}
