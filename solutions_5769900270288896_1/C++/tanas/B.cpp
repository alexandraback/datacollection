#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int inf = 1e9;
const double eps = 1e-7;
const int maxn = 1001000;
const int mod = 1000000007;

int n, m, need;
vi a;
int res;

void go(int d, int k) {
	if (k == need) {
		int sum = 0;
		for (int i = 0; i < n * m; ++i) {
			if (a[i] == 0) continue;
			if (i >= m && a[i - m]) ++sum;
			if (i % m && a[i - 1]) ++sum;
		}
		if (sum < res) {
			res = min(res, sum);
			cout << res << endl;
			for (int i = 0; i < n * m; ++i) {
				if (i && i % m == 0) printf("\n");
				printf("%d", a[i]);
			}
			printf("\n");
			printf("\n");

		}
		return;
	}
	if (d >= n * m) return;
	a[d] = 0;
	go(d + 1, k);
	a[d] = 1;
	go(d + 1, k + 1);
}

pii get(vector<vi> &a) {
	if (a[0][0] == 0) return pii(0, 0);
	if (a[0][m - 1] == 0) return pii(0, m - 1);
	if (a[n - 1][0] == 0) return pii(n - 1, 0);
	if (a[n - 1][m - 1] == 0) return pii(n - 1, m - 1);
	for (int i = 0; i < n; ++i) {
		if (a[i][0] == 0) return pii(i, 0);
		if (a[i][m - 1] == 0) return pii(i, m - 1);
	}
	for (int i = 0; i < m; ++i) {
		if (a[0][i] == 0) return pii(0, i);
		if (a[n - 1][i] == 0) return pii(n - 1, i);
	}
	
	return pii(-1, -1);
}

int main() 
{
#ifdef DEBUG
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> n >> m >> need;
		if (m & 1) swap(n, m);
		a.assign(n * m, 0);
		res = inf;
		//go(0, 0);
		
		int p = 0;
		if (m & 1 && need > (n * m / 2 + 2)) {
			p = 1;
		}
		vector<vi> field(n, vi(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!need) break;
				if (((i+j) & 1) == p) {
					--need;
					field[i][j] = 1;
				}
			}
		}
		
		while (need > 0) {
			pii p = get(field);
			if (p.first == -1) break;
			field[p.first][p.second] = 1;
			--need;
		}
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (need && field[i][j] == 0) {
					--need;
					field[i][j] = 1;
				}
			}
		}
		
		assert(need == 0);
		
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (field[i][j] == 0) continue;
				if (i && field[i - 1][j]) ++res;
				if (j && field[i][j - 1]) ++res;

			}
		}
		
		printf("Case #%d: %d\n", t + 1, res);
	}
	return 0;
}
