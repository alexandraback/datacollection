#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <ctime>
using namespace std;

#define ALL(c) (c).begin(),(c).end()
#define IN(x,c) (find(c.begin(),c.end(),x) != (c).end())
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define FORD(i,a,b) for (int i=(a);i>=(b);i--)
#define INIT(a,v) memset(a,v,sizeof(a))
#define UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

typedef pair<int,int> PII;
typedef long long int64;

int n;
string c[105];
vector<int> f[105];

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int tests;
	cin >> tests;
	FOR (test,1,tests) {
		//fprintf(stderr,"%d/%d\n",test,tests);
		cin >> n;
		REP (k,n) {
			string s;
			cin >> s;
			c[k]="";
			f[k].clear();
			int i=0;
			while (i<s.size()) {
				int j=i+1;
				while (j<s.size() && s[j]==s[i]) j++;
				c[k]+=s[i];
				f[k].push_back(j-i);
				i=j;
			}
		}
		int ok=1;
		vector<vector<int> > have(100);
		REP (k,n) {
			if (c[k]!=c[0]) { ok=0; break; }
			REP (i,(int)f[k].size()) have[i].push_back(f[k][i]);
		}
		int cost=0;
		REP (i,(int)f[0].size()) {
			sort(ALL(have[i]));
			int mid=have[i][n/2];
			REP (j,n) {
				cost+=abs(mid-have[i][j]);
			}
		}
		printf("Case #%d: ",test);
		if (!ok) printf("Fegla Won\n");
		else printf("%d\n",cost);
	}
	return 0;
}
