#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()


int tests, n;
vector<string> str;
vector<int> mid[102];
vector<int> pos;

int main() {
	scanf("%d",&tests);
	for (int test = 1; test <= tests; test++) {	
		printf("Case #%d: ", test);
		str.clear(); pos.clear();
		scanf("%d",&n);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			str.push_back(s);
		}
		
		char last = str[0][0];
		int last_count = 1;
		int next_vec = 0;
		for (int i = 1; i < str[0].size(); i++) {
			if (str[0][i] != last) {
				pos.push_back(last);
				mid[next_vec].clear();
				mid[next_vec].push_back(last_count);
				next_vec++;
				last_count = 1;
				last = str[0][i];
			}
			else last_count++;
		}
		
		pos.push_back(last);
		mid[next_vec].clear();
		mid[next_vec].push_back(last_count);
		next_vec++;
		
		int total_vec = next_vec;
		bool found_er = 0;
		
		for (int k = 1; k < n; k++) {
			last = str[k][0];
			last_count = 1;
			next_vec = 0;
			for (int i = 1; i < str[k].size(); i++) {
				if (str[k][i] != last) {
					if (last != pos[next_vec] || next_vec == total_vec) {
						found_er = 1;
						break;
					}
					mid[next_vec].push_back(last_count);
					next_vec++;
					last_count = 1;
					last = str[k][i];					
				}
				else last_count++;
			}
			if (last != pos[next_vec] || next_vec == total_vec || next_vec < total_vec - 1) found_er = 1;
			if (found_er) break;
			mid[next_vec].push_back(last_count);			
		}
		
				
		int sum = 0;
		for (int i = 0; i < total_vec; i++) {
			sort(mid[i].begin(), mid[i].end());
			for (int j = 0; j < mid[i].size(); j++) {
				//printf("%d %d %d\n",i,j,mid[i][j]);
				if(mid[i][j] > mid[i][mid[i].size() / 2]) sum += mid[i][j] - mid[i][mid[i].size() / 2];
				else sum += mid[i][mid[i].size()/2] - mid[i][j];
			}
		}
		
		if (found_er) printf("Fegla Won\n");
		else printf("%d\n",sum);
	}
}
			

			
		
		


