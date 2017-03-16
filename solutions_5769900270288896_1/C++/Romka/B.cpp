#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

vector<int> a[10010];


int naive(int n, int m, int k) {
	int c[n][m];
	int L = n * m;
	int res = n * m * 4;
	forn(mask, 1 << L) {
		int placed = 0;
		for (int nm = mask, q = 0; q < L; q++, nm >>= 1) {
			c[q / m][q % m] = nm & 1;
			placed += nm & 1;
		}
		if (placed != k) continue;
		int cur = 0;
		forn(i, n)
			forn(j, m) {
				if (i > 0) cur += c[i][j] & c[i-1][j];
				if (j > 0) cur += c[i][j] & c[i][j-1];
			}
		if (cur < res) res = cur;
	}
	return res;
}

int fill(int W, int n, int m, int k) {
	forn(i, n) {
		forn(j, m) {
			a[i][j] = (i + j) % 2 == W;
			k -= a[i][j];
		}
	}
	vector<int> nn;
	forn(i, n)
		forn(j, m)
			if (a[i][j] == 0) {
				int neigh = 0;
				forn(q, 4) {
					int ni = i + di[q];
					int nj = j + dj[q];
					if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
						neigh += a[ni][nj];
					}
				}
				nn.push_back(neigh);
			}
	sort(nn.begin(), nn.end());
	int res = 0;
	forn(i, k) res += nn[i];
	return res;
}

int solve() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int f = (n * m + 1) / 2;
	if (k <= f) return 0;
	set<pair<int, pii>> ss;
	forn(i, n) {
		a[i].clear();
		forn(j, m) {
			a[i].pb(0);
			forn(q, 4) {
				int ni = i + di[q];
				int nj = j + dj[q];
				if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
					a[i][j]++;
				}
			}
			ss.insert(make_pair(-a[i][j], pii(i, j)));
		}
	}
	// forn(i, n) {
	// 	forn(j, m) fprintf(stderr, "%d", a[i][j]); fprintf(stderr, "\n");
	// }
	// fprintf(stderr, "k=%d, n*m=%d\n", k, n*m);
	int zk = k;
	while (k < n * m) {
		k++;
		auto cur = *ss.begin();
		ss.erase(ss.begin());
		int ci = cur.second.first;
		int cj = cur.second.second;
		a[ci][cj] = 0;
		forn(q, 4) {
			int ni = ci + di[q];
			int nj = cj + dj[q];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
				if (a[ni][nj] != 0) {
					ss.erase(ss.find(make_pair(-a[ni][nj], pii(ni, nj))));
					a[ni][nj]--;
					ss.insert(make_pair(-a[ni][nj], pii(ni, nj)));
				}
			}
		}
	}
	int res = 0;
	forn(i, n) forn(j, m) res += a[i][j];
	res /= 2;
	int z = fill(0, n, m, zk);
	if (z < res) res = z;
	z = fill(1, n, m, zk);
	if (z < res) res = z;
	// fprintf(stderr, "");
	// if (res != naive(n, m, zk)) {
	// 	fprintf(stderr, "fail on %dx%d, k=%d: ans is %d, correct is %d\n", n, m, zk, res, naive(n, m, zk));
	// }
	return res;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		printf("%d\n", solve());
	}
	return 0;
}
