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

typedef long long int64;
typedef pair<int64,int64> PII;

int tests;
int n, p[30], s;

int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","wb",stdout);
	cin >> tests;
	FOR (test,1,tests) {
		//cerr << test << endl;
		printf("Case #%d:",test);
		cin >> n;
		s = 0;
		REP (i,n) {
			scanf("%d",&p[i]);
			s += p[i];
		}
		while (s>0) {
			int mi = -1;
			REP (i,n) {
				if (mi==-1 || p[i]>p[mi]) mi=i;
			}
			int mj = -1;
			REP (j,n) if (j!=mi) {
				if (mj==-1 || p[j]>p[mj]) mj=j;
			}
			if (mj==-1) {
				printf(" %c",'A'+mi);
				p[mi]--;
				s-=1;
			} else {
				if (2*p[mj]>s-1) {
					printf(" %c%c",'A'+mi,'A'+mj);
					p[mi]--; p[mj]--;
					s-=2;
				} else {
					printf(" %c",'A'+mi);
					p[mi]--;
					s-=1;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
