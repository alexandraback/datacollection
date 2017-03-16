#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define len(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define hash _hash
#define y0 yy0
#define y1 yy1
#define link _link

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 111;

char buf[N];
vector<pair<char, int> > v[N];

inline void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		v[i].clear();
		int j = 0, len = strlen(buf);
		while (j < len) {
			int z = j;
			while (z + 1 < len && buf[z + 1] == buf[j]) {
				++z;
			}
			v[i].pb(mp(buf[j], z - j + 1));
			j = z + 1;
		}
	}
	for (int i = 1; i < n; ++i) {
		if (sz(v[i]) != sz(v[0])) {
			puts("Fegla won");
			return;
		}
		for (int j = 0; j < sz(v[i]); ++j) {
			if (v[i][j].fs != v[0][j].fs) {
				puts("Fegla won");
				return;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < sz(v[0]); ++i) {
		int res = inf;
		for (int j = 0; j < n; ++j) {
			int cur = 0;
			for (int z = 0; z < n; ++z) {
				cur += abs(v[z][i].sc - v[j][i].sc);
			}
			res = min(res, cur);
		}
		ans += res;
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
		cerr << "TEST " << i << endl;
	}
	return 0;
}
