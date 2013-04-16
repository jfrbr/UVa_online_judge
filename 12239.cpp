#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int v[100],checado[100],restantes,a;

int main()
{
	int n,b;

	while ( scanf("%d %d\n",&n,&b) && n && b)
	{

		restantes = n - b + 1;

		memset(v,0,sizeof(v));
		memset(checado,0,sizeof(checado));

		for (int i =0; i < b; i++)
		{
			scanf("%d",&a);
			v[a] = 1;
			checado[a] = 1;
		}
		if ( b == n+1) // caso que tem todas as bolas
		{	
			printf("Y\n");
			continue;
		}
		for (long int i=0 ; i <= n ; i++)
		{
			if (v[i] == 0) continue;
			for (long int j = i + 1; j <= n ; j++)
			{
				if (!v[j]) 
				{
					continue;
				}
				else
				{
					long int valor = labs(i - j);
					if (!checado[valor])
					{
						checado[valor] = 1;
						restantes--;
					}	
				}	
			}
			if (!restantes) break;
		}
		if (!restantes)  printf ("Y\n");
		else printf ("N\n");
		
	}

	return 0;
}
