#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){

	vector<int> v,m;
	m.assign(3,0);
	v.assign(3,0);
	while(scanf("%d %d %d %d %d\n",&v[0],&v[1],&v[2],&m[0],&m[1]) > 0){
		if (v[0] == v[1]) break;
		m[2] = 53;
		sort(v.begin(),v.end());
		sort(m.begin(),m.end());
		int k;
		if (v[2] < m[0]){
			m[2] = 1;
			for (int i = 0; (i < 3)&&(m[2] == v[i]);i++) m[2]++; 
		} else {
			if (v[1] < m[0]){
				m[2] = (v[1] + 1);
				if ((v[2] == m[2])||(m[2] == m[1])||(m[2] == m[0])) m[2]++;	
				if ((v[2] == m[2])||(m[2] == m[1])||(m[2] == m[0])) m[2]++;	
				if ((v[2] == m[2])||(m[2] == m[1])||(m[2] == m[0])) m[2]++;	
			} else {
				if (v[2] < m[1]){
					m[2] = (v[2] + 1);
					if (m[2] == m[1]) m[2]++;
				} else m[2] = -1; 	
			}
		}
		if (53 != m[2])printf("%d\n",m[2]);
		else printf("-1\n");
	}
}
