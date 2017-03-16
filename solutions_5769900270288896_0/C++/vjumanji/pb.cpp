#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
#define REP(i,a) FOR(i,0,a)
#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)

typedef long long int LL;
typedef vector<int> vi;

int rint() { int x; scanf("%d", &x); return x;}
int rLL() { LL x; scanf("%lld", &x); return x;}

int r, c, n;

int g[16][16];

int solve() {
	int t = r*c, minnoise = -1;
	REP(i,1<<t) {
		int j = 0, occupents = 0;
		// REP(p,16) REP(q,16) g[i][j] = 0;
		REP(k,t) if (i & (1<<k)) {
			g[k/c][k%c] = 1;
			occupents++;
		}
		else {
			g[k/c][k%c] = 0;
		}
		if (occupents == n) {
			int noise = 0;
			REP(p,r) REP(q,c) if (g[p][q]) {
				if (p-1 >= 0 && g[p-1][q]) noise++;
				if (p+1 < r && g[p+1][q]) noise++;
				if (q-1 >= 0 && g[p][q-1]) noise++;
				if (q+1 < c && g[p][q+1]) noise++;
			}
			// printf("%d,%d\n", i, noise);
			noise /= 2;
			if (minnoise == -1 || minnoise > noise)
				minnoise = noise;
		}
	}
	return minnoise;
}

int main() {
	int t = rint();
	REP(i, t) {
		cin >> r >> c >> n;
		if (r > c) swap(r,c);
		printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}