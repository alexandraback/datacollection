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
#define PRESENT(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define FORD(i,a,b) for (int i=(a);i>=(b);i--)
#define INIT(a,v) memset(a,v,sizeof(a))
#define UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

typedef pair<int,int> PII;
typedef long long int64;

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int tests;
	scanf("%d",&tests);
	FOR (test,1,tests) {
		printf("Case #%d: ",test);
		int r[2];
		set<int> g[2][4];
		REP (k,2) {
			scanf("%d",&r[k]);
			r[k]--;
			int x;
			REP (i,4) {
				REP (j,4) {
					scanf("%d",&x);
					g[k][i].insert(x);
				}
			}
		}
		vector<int> c;
		set_intersection(ALL(g[0][r[0]]),ALL(g[1][r[1]]), back_inserter(c));
		if (c.size()==0) printf("Volunteer cheated!\n");
		else if (c.size()>1) printf("Bad magician!\n");
		else printf("%d\n",c[0]);
	}
	return 0;
}
