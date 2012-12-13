#include <cstdio>
#include <cstring>

#define MAX 100000

using namespace std;

int n,k,array[MAX],a1,a2,tree[MAX];

char op;

void construction(int node,int intStart,int intEnd,int tree[MAX],int array[MAX], int arraySize){


	if ( intStart == intEnd){
		tree[node] = intEnd;
	}else{
	
		construction(2*node,intStart,(intStart+intEnd)/2,tree,array,arraySize);
		construction(2*node+1,(intStart+intEnd)/2 + 1,intEnd,tree,array,arraySize);
		
		if ( array[ tree[2*node] ]  * array[ tree[2*node + 1] ]  > 0){
			tree[node] = 1;
		}else if ( array[ tree[2*node] ]  * array[ tree[2*node + 1] ]  == 0 ){
			tree[node] = 0;
		}else{
			tree[node] = -1;
		}
	}
}

void update(int modified,int node, int intStart,int intEnd,int tree[MAX],int array[MAX], int arraySize){


	if ( intStart == intEnd){
		tree[node] = intEnd;
	}else{
		
		if (modified <= (intStart+intEnd)/2 ){
		
			update(modified,2*node,intStart,(intStart+intEnd)/2,tree,array,arraySize);
			
			if (  array[ tree[node] ] * array[ tree[2*node] ] > 0){
				tree[node] = 1;
			}else if ( array[ tree[node] ] * array[ tree[2*node] ] == 0 ){
				tree[node] = 0;
			}else{
				tree[node] = -1;
			}
		}else{
		
			update(modified,2*node+1,(intStart+intEnd)/2+1,intEnd,tree,array,arraySize);
			
			if (  array[ tree[node] ] * array[ tree[2*node] ] > 0){
				tree[node] = 1;
			}else if ( array[ tree[node] ] * array[ tree[2*node+1] ] == 0 ){
				tree[node] = 0;
			}else{
				tree[node] = -1;
			}
		}
	}
}

int query (  int node, int intStart, int intEnd, int tree[MAX], int array[MAX], int queryStart, int queryEnd ){

	int p1,p2;
	
	if ( queryStart > intEnd || queryEnd < intStart){
		return -1;
	}
	
	if ( intStart >= queryStart &&  intEnd <= queryEnd){
		return tree[node];
	}
	
	p1 = query (2*node,intStart, (intStart+intEnd)/2,tree,array,queryStart,queryEnd );
	p2 = query (2*node+1,(intStart+intEnd)/2+1, intEnd,tree,array,queryStart,queryEnd ); 

}

int main(){


	while(!feof(stdin)){
	
		memset(array,0,sizeof(array));
		memset(tree,0,sizeof(tree));
		
		scanf("%d %d\n",&n,&k);
		
		for (int i=0; i<n;i++) scanf("%d",&array[i]);
		
		construction(0,0,n-1,tree,array,n);
		
		while(k--){
			scanf("%c %d %d\n",&op,&a1,&a2);
			
			if ( op == 'C'){
				
//				update();
			
			}else if ( op == 'P'){
				
	// read			
				
			}
		}
			
		
	}
	

	return 0;
}

