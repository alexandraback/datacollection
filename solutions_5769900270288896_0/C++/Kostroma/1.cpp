#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {
}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//#define int li



void solve() {
	int r, c, n;
	cin >> r >> c >> n;
	if (n <= (r * c + 1) / 2) {
		cout << "0\n";
		return;
	}

	int All = 1 << (r * c);

	int res = 1e9;
	vector<vector<int>> a(r, vector<int>(c, 0));
	for (int mask = 0; mask < All; ++mask) {
		a.assign(r, vector<int>(c, 0));
		int cnt = 0;
		for (int z = 0; z < r * c; ++z) {
			if (mask & (1 << z)) {
				++cnt;
				a[z / c][z % c] = 1;
			}
		}
		if (cnt != n) {
			continue;
		}

		int cur = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (!a[i][j])
					continue;
				if (i + 1 < r && a[i + 1][j])
					++cur;
				if (j + 1 < c && a[i][j + 1])
					++cur;
			}
		}
		res = min(res, cur);

	}
	cout << res << "\n";
}


