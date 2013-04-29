#include <cstdio>
#include <cstring>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int t,n,gnus,aligned,max_aligned,cases=1,zero_d_x=0;
float x,y,d_x,d_y,coef;

typedef pair<float,float> ff;

int main(){

	scanf("%d\n",&t);

	while(t--){

		scanf("%d\n",&n);

		map <ff, int> m;
		map <ff,int>:: iterator m_it;
		vector<ff> v;
		
		gnus = max_aligned = 0;

		while(n--){

			scanf("%f %f\n",&x,&y);
			if (!m[ff(x,y)]){ 
				m[ff(x,y)] = 1;
				gnus++;
				v.push_back( ff(x,y));
			}
		}

		for (int i=0; i < v.size(); i++){

			aligned = zero_d_x = 1;
			map<float, int> m_ang;
			map<float,int> :: iterator m_ang_it;

			for (int j=i+1; j < v.size(); j++){

				d_x = v[i].first - v[j].first;
				d_y = v[i].second - v[j].second;

				if ( d_x != 0){

					coef = tan(d_y/d_x);
			//		printf("coef = %f\n",coef);
					if (m_ang[coef] == 0) m_ang[coef]++;
					m_ang[coef]++;

					aligned = max(aligned,m_ang[coef]);
					
				}else{
					zero_d_x++;

					aligned = max(aligned,zero_d_x);
				}
			}
			max_aligned = max(max_aligned,aligned);
		}
		if (gnus == 1) printf("Data set #%d contains a single gnu.\n",cases++);
		else printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n",cases++,gnus,max_aligned);
	}
	
	return 0;

}
