#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int i, j, k, m, n, l;

int stupid() {
	int ans = 100000000;

	l = m * n;
	F0(mask, (1 << l)) if (bc(mask) == k) {
		int bad = 0;
		F0(i, l) if ((1 << i)&mask) F0(j, i) if ((1 << j)&mask) {
			int x1 = i / n, x2 = i % n;
			int y1 = j / n, y2 = j % n;
			if (abs(x1 - y1) + abs(x2 - y2) == 1) bad++;
		}
		ans = min(ans, bad);
	}
	return ans;
}

int solve() {
	int ans = 100000000;

	for (int mode = 0; mode < 2; mode++) {
		int f[5] = { 0 };
		F0(i, m) F0(j, n) if ((i + mode) % 2 == j % 2) f[0]++;
		else {
			int cnt = 0;
			F0(k, 4) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && x < m && y >= 0 && y < n) cnt++;
			}
			f[cnt]++;
		}
		int s = 0, left = k;
		F0(i, 5) {
			int x = min(left, f[i]);
			s += x * i;
			left -= x;
		}
		ans = min(ans, s);
	}
	return ans;
}

void show(int m, int n) {
	for (int k = 0; k <= m * n; k++) {
		int ans = 100000000;

		l = m * n;
		int best = -1;
		F0(mask, (1 << l)) if (bc(mask) == k) {
			int bad = 0;
			F0(i, l) if ((1 << i)&mask) F0(j, i) if ((1 << j)&mask) {
				int x1 = i / n, x2 = i % n;
				int y1 = j / n, y2 = j % n;
				if (abs(x1 - y1) + abs(x2 - y2) == 1) bad++;
			}
			if (bad <= ans) {
				ans = bad;
				best = mask;
			}
		}

		cerr << endl << ans << endl;
		F0(i, m) {
			F0(j, n) {
				char c = '.'; if ((1 << ((m-i-1) * n + (n-j-1))) & best) c = '#';
				cerr << c;
			}
			cerr << endl;
		}
	}
}

int main() {
    //freopen("x.in", "r", stdin);

	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w", stdout);

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;

//	show(5, 5);

	F1(tt,tn) {

		cin >> m >> n >> k;

		int ans = solve();
  		printf("Case #%d: ", tt);
		cout << ans << endl;
	}
	return 0;
}
