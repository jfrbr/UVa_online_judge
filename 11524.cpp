#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n;
double r,n1,m1,n2,m2,n3,m3,p1,p2,p3;
double mn1,mm1,mn2,mm2,mn3,mm3;
double lado1,lado2,lado3,semiperimetro,areasuposta,rsuposto;

int main(){

    scanf("%d\n",&n);

    while(n--){
        scanf("%lf\n%lf %lf\n%lf %lf\n%lf %lf\n",&r,&m1,&n1,&m2,&n2,&m3,&n3);
        
        mn1 = n1;
        mm1 = m1;
        
        mm2 = mn1;
        mn2 = mm2 * n2/m2;

        mn3 = mm1;
        mm3 = mn3* m3/n3;

        lado1 = mn1+mm1;
        lado2 = mn2+mm2;
        lado3 = mn3+mm3;

        semiperimetro = (lado1+lado2+lado3)*0.5;
        areasuposta = sqrt(semiperimetro*(semiperimetro-lado1)*(semiperimetro-lado2)*(semiperimetro-lado3));
        rsuposto = areasuposta/semiperimetro;

        printf("%.4lf\n",areasuposta*(r*r/(rsuposto*rsuposto)));
              
    }
    
    return 0;
}
