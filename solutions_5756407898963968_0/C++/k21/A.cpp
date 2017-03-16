#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int main() {
	int T;
	scanf("%d", &T);
	REP(t,T) {
		vector<bool> opts;
		REP(i,16) opts.push_back(true);
		int ans;
		REP(m,2) {
			scanf("%d", &ans);
			FOR(row,1,4) REP(i,4) {
				int card;
				scanf("%d", &card);
				--card;
				if (row != ans) opts[card] = false;
			}
		}
		int cnt = 0, res = -1;
		REP(i,16) {
			if (opts[i]) {
				++cnt;
				res = i+1;
			}
		}
		printf("Case #%d: ", t+1);
		if (cnt == 0) {
			printf("Volunteer cheated!\n");
		} else if (cnt == 1) {
			printf("%d\n", res);
		} else {
			printf("Bad magician!\n");
		}
	}
	return 0;
}
