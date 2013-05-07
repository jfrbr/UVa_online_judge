#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> ii;

int t,n,w,x,y;
double sum,initial, amount, falling, initial_vol,perc,vol;

int main(){

    scanf("%d\n\n",&t);

    while(t--){
    
        scanf("%d\n",&n);
        sum = initial = amount = falling = 0;
        vector <ii> v;
        
        while(n--){
            scanf("%d %d\n",&x,&y);
            v.push_back(ii(x,y));
        }
        for (int i=0; i < (int) v.size() - 1; i++){
            sum += v[i].first*v[i+1].second - v[i+1].first*v[i].second;
        }
        sum = sum/2.0;
        
        scanf("%d\n%lf%lf%lf\n",&w,&initial,&amount,&falling);

        vol = sum * w;

        initial_vol = vol*initial/100;

        initial_vol -= amount;

        if (initial_vol < 0){
            printf("Lack of water. ");
            initial_vol = 0;
        }

        initial_vol += falling;

        if (initial_vol > vol){
            printf("Excess of water. ");
            initial_vol = vol;
        }

        perc = initial_vol/vol*100;

        printf("Final percentage: %d%%\n",(int)floor(perc));

        
    }


    return 0;
}
