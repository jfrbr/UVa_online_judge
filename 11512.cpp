#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int n, t, k = 2;
string dna;

struct {
	int index;
	string dna;
}typedef t_dna;

bool compare (t_dna a, t_dna b){
	return lexicographical_compare(a.dna.begin(),a.dna.end(), b.dna.begin(), b.dna.end());
}

string check_prefix (string a, string b){

	int s = max ( (int) a.size(), (int) b.size() );
	string p;
	
	for (int i=0; i<s;i++){
		if (a[i] != b[i]) break;
		else p+=a[i];
	}
	
	return p;
}

int main(){

	scanf("%d\n",&t);

	while(t--){
		
		getline(cin,dna);
		dna.append("$");
				
		n = dna.size();

		vector<t_dna> suffix(n);
		
		for (int i=0; i < n;i++){
			t_dna a;
			a.dna = string(dna.begin() + i, dna.end());
			a.index = i;
			suffix[i] = a;
		}
		sort(suffix.begin(), suffix.end() , compare);
	
		int best = 0;	
		string s_best;		

		for (int i=1; i<n;i++){

			string a = check_prefix( suffix[i-1].dna, suffix[i].dna);
			if ( (int)a.size() > best) {
				best = (int)a.size();
				s_best = a;
			}			
		}
		if ( best == 0){
			printf("No repetitions found!\n");
			continue;
		}else{
			int occur = 0;
			
			for (int i=0; i < (int) dna.size() - best; i++){
				string a = string(dna.begin() + i, dna.begin() + i + best);
				if ( s_best == a) occur++;
			}
			printf("%s %d\n",s_best.c_str(), occur);
		}		
	}

	return 0;
}
