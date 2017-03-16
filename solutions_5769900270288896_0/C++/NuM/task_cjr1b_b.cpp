#pragma comment(linker, "/stack:32000000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>
#include <string.h>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void solve_wa() {
	int r, c, n; scanf("%d%d%d", &r, &c, &n);
	int emp = r * c - n;
	vector<vector<int> > a(r, vector<int>(c));
	int ans = (r-1)*c + (c - 1) * r;
	forn(iter, emp) {
		int besti = -1;
		int bestj = -1;
		int bestres = -1;
		forn(i, r) forn(j, c) {
			if (a[i][j]) continue;
			int cc = 0;
			forn(k, 4) {
				int ti = i + dx[k];
				int tj = j + dy[k];
				if (ti >= 0 && ti < r && tj >= 0 && tj < c && a[ti][tj] == 0) ++cc;
			}
			if (cc > bestres) {
				bestres = cc;
				besti = i;
				bestj = j;
			}
		}
		a[besti][bestj] = iter+1;
		ans -= bestres;
	}
	printf("%d\n", ans);
}

int a[20][20];
int r, c;
const int cinf = 1000000010;
int best;
void rec(int i, int j, int rem, int res) {
	if (res >= best) return;
	int ni = i;
	int nj = j + 1;
	if (nj == c) nj = 0, ni++;
	if (i == r) {
		if (rem == 0) best = min(best, res);
		return;
	}
	forn(val, 2) {
		a[i][j] = val;
		if (rem - val < 0) continue;
		int cc = 0;
		if (val && i && a[i-1][j]) ++cc;
		if (val && j && a[i][j-1]) ++cc;
		rec(ni, nj, rem-val, res + cc);
	}
}

void solve() {
	 int n; scanf("%d%d%d", &r, &c, &n);
	 best = cinf;
	 rec(0, 0, n, 0);
	 printf("%d\n", best);
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; scanf("%d", &T);
	for (int tn = 1; tn <= T; ++tn) {
		printf("Case #%d: ", tn);
		solve();
	}
	return 0;
}