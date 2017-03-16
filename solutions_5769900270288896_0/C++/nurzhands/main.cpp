#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define ms(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> pt;

const int N = 1<<17;
const int inf = 1<<30;

int a[100][100];

int main() {
	freopen("a.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d\n", &T);
	for (int t = 1; t <= T; t++) {
		int n, m, k;
		cin >> n >> m >> k;
		int l = n * m;
		int ans = inf;
		ms(a, 0);
		for (int mask = 0; mask < (1<<l); mask++)
		if (__builtin_popcount(mask) == k) {
			for (int i = 0; i < l; i++)
				if ((mask >> i) & 1)
					a[i/m][i%m] = 1;
				else
					a[i/m][i%m] = 0;
			int cur = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					cur += j+1 < m && a[i][j] && a[i][j+1];
					cur += i+1 < n && a[i][j] && a[i+1][j];
				}
			ans = min(ans, cur);
		}
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}