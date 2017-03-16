#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))

#define bug(x) cout << #x" = " << x << endl
#define bug2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl
#define bug3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl
#define bug4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 105, M = 105;

int T, n;
char s[M];
vector< pair<int, int> > a[N];
vi h;

void gao(char s[M], int id) {
	int i, j;
	int sz = strlen(s);
	a[id].clear();
	for (i = 0; i < sz; i++) {
		j = i;
		while (i + 1 < sz && (s[i + 1] == s[i])) i++;
		a[id].pb(mp(s[j] - 'a', i - j + 1));
	}
}

bool judge() {
	int sz = a[0].size();
	FOR (i, 1, n - 1) {
		if (SZ(a[i]) != sz) return 0;
		rep (j, sz) {
			if (a[0][j].X != a[i][j].X) return 0;
		}
	}
	return 1;
}

int main() {
	int cas = 0, ans, sz;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cas);
		scanf("%d", &n);
		rep (i, n) {
			scanf("%s", s);
			gao(s, i);
		}
		if (!judge()) puts("Fegla Won");
		else {
			ans = 0, sz = a[0].size();
			rep (i, sz) {
				h.clear();
				rep (j, n) h.pb(a[j][i].Y);
				sort(ALL(h));
				rep (j, n) ans += abs(h[j] - h[n / 2]);
			}
			printf("%d\n", ans);
		}
	}
    return 0;
}
