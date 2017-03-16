#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

typedef pair<ld, ld> pt;
#define sqr(x) ((x) * (x))
#define ft first
#define sc second
#define x first
#define y second

const int N = 20;
int ans[N][N][N];
int n, m, k;

bool read() {
	cin >> n >> m >> k;
    return true;
}

bool cur[N][N];

int calc(int a, int b) {
	int res = 0;
	forn (i, a)
		forn (j, b - 1) {
			res += cur[i][j] && cur[i][j + 1];
	}
	forn (i, a - 1)
		forn (j, b) {
			res += cur[i][j] && cur[i + 1][j];
	}

	return res;
}

void go(int a, int b) {
	int n = a * b;
	forn (i, n + 1)
		ans[a][b][i] = INF;
	forn (i, 1 << n) {
		int cnt = 0;
		forn (j, n) {
			int t = (i & (1 << j)) > 0;
			cnt += t;
			cur[j / b][j % b] = t;
		}
		ans[a][b][cnt] = min(ans[a][b][cnt], calc(a, b));
	}
}

void solve() {

	if (n > m)
		swap(n, m);
	cout << ans[n][m][k] << endl;
 }

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	for (int a = 1; a <= 16; ++a)
		for (int b = 1; b <= a; ++b) {
			if (a * b <= 16) {
				go(b, a);
			}
		}

	int tc;
	cin >> tc;

	forn (i, tc) {
		read();
		cout << "Case #" << i + 1 << ": ";
        solve();
	}
    
    return 0;
}