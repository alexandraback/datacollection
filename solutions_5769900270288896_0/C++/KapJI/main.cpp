#include <cassert>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> st;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e6 + 100;

int dp[20][20][20];

int get_rev(int n) {
	stringstream ss;
	ss << n;
	string s = ss.str();
	reverse(s.begin(), s.end());
	return atoi(s.c_str());
}

inline bool get_bit(int mask, int n) {
	return mask & (1 << n);
}

void precalc() {
	for (int r = 1; r <= 16; ++r) {
		for (int c = 1; c <= 16; ++c) {
			for (int n = 0; n <= 16; ++n) {
				dp[r][c][n] = INF;
			}
		}
	}
	for (int r = 1; r <= 16; ++r) {
		for (int c = 1; c <= r; ++c) {
			if (r * c <= 16) {
				int m = r * c;
				for (int mask = 0; mask < (1 << m); ++mask) {
					int n = __builtin_popcount(mask);
					int unh = 0;
					for (int i = 0; i < m; ++i) {
						if (get_bit(mask, i)) {
							if (i + c < m && get_bit(mask, i + c)) {
								unh++;
							}
							if ((i + 1) % c != 0 && get_bit(mask, i + 1)) {
								unh++;
							}
						}
					}
					dp[r][c][n] = min(dp[r][c][n], unh);
					dp[c][r][n] = min(dp[c][r][n], unh);
				}
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    precalc();
    FOR(i, t) {
    	int r, c, n;
    	scanf("%d%d%d", &r, &c, &n);
        printf("Case #%d: %d\n", i + 1, dp[r][c][n]);
    }
	return 0;
}

