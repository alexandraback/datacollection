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
#define REP(i,n) for (int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define INIT(a,v) memset(a,v,sizeof(a))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

typedef pair<int,int> PII;
typedef long long int64;

int tests;
int n,r,c;

inline int ok(int y, int x) {
	return (0<=y && y<r && 0<=x && x<c);
}

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","wb",stdout);
	cin >> tests;
	FOR (test,1,tests) {
		cerr << test << endl;
		cin >> r >> c >> n;
		vector<vector<int> > grid;
		vector<int> row;
		REP (i,c) row.push_back(0);
		REP (i,r) grid.push_back(row);
		int best=4*r*c;
		REP (m,1<<(r*c)) {
			REP (i,r*c) {
				int y=i/c, x=i%c;
				grid[y][x]=(m&(1<<i));
			}
			int u=0, a=0;
			REP (y,r) REP (x,c) if (grid[y][x]) {
				a++;
				if (ok(y+1,x) && grid[y+1][x]) u++;
				if (ok(y-1,x) && grid[y-1][x]) u++;
				if (ok(y,x+1) && grid[y][x+1]) u++;
				if (ok(y,x-1) && grid[y][x-1]) u++;
			}
			if (a==n) best=min(best, u/2);
		}
		printf("Case #%d: %d\n",test,best);
	}
	return 0;
}
