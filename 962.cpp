#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

#define MAX 1000100000

using namespace std;

int n1,rg, ci,cj;
bool have;

int cube(int n){
	return n*n*n;
}

int main(){


	vector<int> cab_numbers;

	map<int, int> m;

	for (int i=1 ; i < 1002;i++){
		for (int j=i; j < 1002; j++){
			ci = cube(i);cj = cube(j);
			
			if (ci + cj > MAX) break;

			m[ci+cj]++;
			if ( m[ci+cj] == 2){
				cab_numbers.push_back(ci+cj);
			}
		}
	}

	sort(cab_numbers.begin(), cab_numbers.end());
	
	while (!feof(stdin)){

		have = false;

		vector<int>::iterator it;

		scanf("%d\n%d\n",&n1,&rg);

		for (it = cab_numbers.begin(); it != cab_numbers.end(); it++){
			
			if (*it >= n1 && *it <= n1 + rg){
				printf("%d\n",*it);
				have = true;
			}
			else if (*it > n1 + rg) break;		
		}
		if (!have) printf("None\n");
		
	}

	return 0;
}
