#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
typedef long long int64;

int main() {
	int tN;
	scanf("%d", &tN);
	FOR(cN, 1, tN) {
		int n, r, c, k;
		scanf("%d%d%d", &r, &c, &k);
		n = r * c;
		int ans = 4 * n;
		REP(b, 1 << n) {
			int cnt = 0;
			REP(i, n) if (b & (1 << i)) ++cnt;
			if (cnt == k) {
				int score = 0;
				REP(i, r)
				REP(j, c) {
					int x = i*c + j;
					if ((b & (1 << x)) == 0) continue;
					if (i < r-1 && (b & (1 << (x+c)))) ++score;
					if (j < c-1 && (b & (1 << (x+1)))) ++score;
				}
				ans = min(ans, score);
			}
		}
		printf("Case #%d: %d\n", cN, ans);
	}
}
