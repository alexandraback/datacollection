#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 5;

int n, m, k;
int dp[100][100][1 << N];

inline void solve() {
	cin >> n >> m >> k;
	if (n < m) {
		swap(n, m);
	}
	for (int i = 0; i <= n; i++) {
		for (int z = 0; z <= k; z++) {
			for (int j = 0; j < (1 << m); j++) {
				dp[i][z][j] = inf;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int z = 0; z < (1 << m); z++) {
				if (dp[i][j][z] >= inf) {
					continue;
				}
				for (int l = 0; l < (1 << m); l++) {
					int nj = j + __builtin_popcount(l), nans = dp[i][j][z] + __builtin_popcount(l & z) + __builtin_popcount(l & (l >> 1));
					dp[i + 1][nj][l] = min(dp[i + 1][nj][l], nans);
				}
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < (1 << m); i++) {
		ans = min(ans, dp[n][k][i]);
	}
	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
    return 0;
}
