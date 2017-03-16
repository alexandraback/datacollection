#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

int m;
int n;

int w[10000][10000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int getcol(int x, int y) {
	int ans = 0;
	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			if (w[nx][ny])
				ans++;
	}
	re ans;
}

int getsimple(int n, int m, int k) {
	int ans = n * m * 2;
	int bmask = 0;
	rep(mask, (1 << (n * m))) {
		if (__builtin_popcount(mask) != k)
			continue;
		int matr[20][20];
		fill(matr, 0);
		rep(i, n) rep(j, m)
			matr[i][j] = ((mask & (1 << (i * m + j))) != 0);
		int c = 0;
		rep(i, n) rep(j, m) {
			if (matr[i][j] && matr[i][j + 1])
				c++;
			if (matr[i][j] && matr[i + 1][j])
				c++;
		}

		if (ans > c) {
			ans = min(ans, c);

			/*
			bmask = mask;
			cout << c << endl;
			rep(i, n) {
				rep(j, m)
					cout << matr[i][j] << ' ';
				cout << endl;
			}
			cout << endl;*/
		}
	}
	//cout << bmask << endl;
	re ans;
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {

		int k;
		cin >> n >> m >> k;
		cout << "Case #" << tt + 1 << ": ";

		/*
		if (k <= (n * m + 1) / 2)
			continue;
		if (k == n * m || k == n * m - 1)
			continue;

		cout << n << ' ' << m << ' ' << k << endl;*/
		cout << getsimple(n, m, k) << endl;
		continue;

		rep(i, n) rep(j, m)
			w[i][j] = ((i + j) % 2 == 0);

		vector<pair<int, ii> > v;
		rep(i, n) rep(j, m)
			if (w[i][j])
				k--;
			else
				v.pb(mp(getcol(i, j), mp(i, j)));

		int ans = 0;
		sort(all(v));
		rep(i, k) {
			ans += v[i].fi;
			w[v[i].se.fi][v[i].se.se] = 1;
		}

		rep(o, 8 * min(n, m))
		rep(i, n) rep(j, m)
		if (w[i][j]) {
			int c = getcol(i, j);
			rep(o, 4) {
				int ni = i + dx[o];
				int nj = j + dy[o];
				if (ni >= 0 && ni < n && nj >= 0 && nj < m)
					if (!w[ni][nj]) {
						int c1 = getcol(ni, nj);
						int d = c - c1 + 1;
						if (d > 0) {
							w[i][j] = 0;
							w[ni][nj] = 1;
							ans -= d;
							break;
						}
					}
			}
		}

		cout << ans << endl;
	}

	re 0;
}
