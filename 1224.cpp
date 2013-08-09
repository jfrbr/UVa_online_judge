#include <cstdio>
#include <cstring>

using namespace std;

int t,n,dp[50],ts[50];

int main(){

    scanf("%d\n",&t);
    memset(dp,0,sizeof(dp));
    memset(ts,0,sizeof(ts));
    
    dp[0]=1;
    dp[1]=1;
    
    for (int i=2;i<32;++i)
        dp[i]=dp[i-1]+2*dp[i-2];
    

    ts[0]=1;
    ts[1]=1;
    ts[2]=3;
    ts[3]=1;            
    
    for (int i=4; i < 32;++i)
        ts[i]=ts[i-2]+2*ts[i-4];
    
    while (t--){
    
        scanf("%d\n",&n);
        printf("%d\n",(dp[n]-ts[n])/2 + ts[n]);
        
    }
    


    return 0;
}
