#include <cstdio>
#include <cstring>

#define MAX 500000

#define ERROR -2

using namespace std;

int n,k,array[MAX],a1,a2,tree[MAX],a;
char op;

void construction(int node,int intStart,int intEnd){

	if ( intStart == intEnd){

		if ( array[intEnd] < 0) tree[node] = -1;
		else if ( array[intEnd] == 0 ) tree[node] = 0;
		else tree[node] = 1;
	}else{
	
		construction(2*node,intStart,(intStart+intEnd)/2);
		construction(2*node+1,(intStart+intEnd)/2 + 1, intEnd);
		
		if ( tree[2*node]   * tree[2*node + 1] > 0){
			tree[node] = 1;
		}else if ( tree[2*node]   *  tree[2*node + 1]   == 0 ){
			tree[node] = 0;
		}else{
			tree[node] = -1;
		}
	}
}

void update(int modified,int node, int intStart,int intEnd){


	if ( intStart == intEnd){
		if ( array[intEnd] < 0) tree[node] = -1;
		else if ( array[intEnd] == 0 ) tree[node] = 0;
		else tree[node] = 1;
	}else{
		
		if (modified <= (intStart+intEnd)/2 ){
		
			update(modified,2*node,intStart,(intStart+intEnd)/2);
			
			if (  tree[2*node]  * tree[2*node+1]  > 0){
				tree[node] = 1;
			}else if ( tree[2*node]  *  tree[2*node+1]  == 0 ){
				tree[node] = 0;
			}else{
				tree[node] = -1;
			}
		}else{
		
			update(modified,2*node+1,(intStart+intEnd)/2+1,intEnd);
			
			if (  tree[2*node]*tree[2*node+1]  > 0){
				tree[node] = 1;
			}else if (  tree[2*node]*tree[2*node+1]  == 0 ){
				tree[node] = 0;
			}else{
				tree[node] = -1;
			}
		}
	}

}
int query (  int node, int intStart, int intEnd, int queryStart, int queryEnd ){

	int p1,p2;
	
	if ( queryStart > intEnd || queryEnd < intStart){
		return ERROR;
	}
	
	if ( intStart >= queryStart &&  intEnd <= queryEnd){

		
		return tree[node];
	}
	
	p1 = query (2*node,intStart, (intStart+intEnd)/2,queryStart,queryEnd );
	p2 = query (2*node+1,(intStart+intEnd)/2+1, intEnd,queryStart,queryEnd );

	if (p1==ERROR){
		return p2;
	} 
	if (p2==ERROR){
		return p1;
	}
	
	return p1*p2;
}

int main(){


	while(!feof(stdin)){
	
		memset(array,0,sizeof(array));
		memset(tree,0,sizeof(tree));
		
		scanf("%d %d\n",&n,&k);
		
		for (int i=0; i<n;i++) scanf("%d",&array[i]);
		
		scanf("\n");

		construction(1,0,n-1);
		
		while(k--){
			scanf("%c %d %d\n",&op,&a1,&a2);

			if ( op == 'C'){
				a1--;
				array[a1] = a2;
				update(a1,1,0,n-1);

			}else if ( op == 'P'){
				a1--;a2--;
				int res = query(1,0,n-1,a1,a2);
				
				if ( res > 0) printf("+");
				else if ( res < 0) printf("-");
				else printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}

