#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n,steps,words[300][300],vis[300];
char line[150],src[150],dest[150];

bool one_char_diff ( string s1, string s2 ){

	int diffs=0;

	for (int i=0; i < s1.size(); i++){
		if (  s1[i] != s2[i] ) diffs++;
		if ( diffs > 1 ) return false;
	}
	return true;

}

void bfs( int start, int end , int length){
	
	queue<int> q;

	q.push(start);

	while (!q.empty () ){
	
		int tam = q.size();
		while (tam--){

			int front = q.front();
			q.pop();

			if (front == end) return;
		
			for (int i=0 ; i < length; i++){
				if ( words[front][i] && !vis[i] ){
					q.push(i);
				}
			}
			vis[front] = 1;
		}
		steps++;
	}
}

int main(){

	scanf("%d\n",&n);
	while (n--){

		scanf("\n");
		memset(words,0,sizeof(words));

		map < string, int> mw;
		vector <string> v;

		while ( gets(line) && strlen(line) > 0  && line[0] != '*'){
			v.push_back(string(line));
		}

		sort( v.begin() , v.end());

		for (int i=0 ; i < (int) v.size() ; i++){
			mw[ v[i] ] = i;
			for (int j=0 ; j < (int) v.size();j++){
				if ( i == j) continue;
				else if ( v[i].size() == v[j].size()  ){
					if ( one_char_diff( v[i],v[j]) ) 
						words[i][j] = 1;
				}
			}
		}
		while ( gets(line) && strlen(line) > 0 ){
			sscanf(line,"%s %s",src,dest);
			memset(vis,0,sizeof(vis));
			steps=0;
			bfs( mw[string(src)], mw[string(dest)], (int) v.size() );
			printf("%s %s %d\n",src,dest,steps);
		}
		if (n) printf("\n");
	}
	return 0;
}
