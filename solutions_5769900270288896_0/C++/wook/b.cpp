#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)
#define all(x) (x).begin(), (x).end()

#define TWO(x) (1<<(x))
int R, C, n;

int get_unhappiness(int s) {
	bool a[16][16] = {0};
	for(int i=0; i<R; ++i) {
		for(int j=0; j<C; ++j) {
			a[i][j] = !!(TWO(i * C + j) & s);
		}
	}
	int h = 0;
	for(int i=0; i<R; ++i) {
		for(int j=1; j<C; ++j) {
			if(a[i][j-1] && a[i][j]) h ++;
		}
	}
	for(int j=0; j<C; ++j) {
		for(int i=1; i<R; ++i) {
			if(a[i-1][j] && a[i][j]) h++;
		}
	}
	return h;
}

int go() {

	int ans = 987987987;
	for(int s = 0; s < TWO(R*C); ++ s) {
		int k = __builtin_popcount(s);
		if(k != n) continue;

		int t = get_unhappiness(s);
		ans = min(ans, t);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	for(int t=1; t<=T; ++t) {
		cin >> R >> C >> n;
		printf("Case #%d: %d\n", t, go());
	}
	return 0;
}

