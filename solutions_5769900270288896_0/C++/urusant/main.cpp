#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rs resize
#define mp make_pair
#define pi 3.1415926535897932384626433832795
#define sz(a) (int)(a).size()
#define Sort(a) sort((a).begin(), (a).end())
#define Reverse(a) reverse((a).begin(), (a).end())
#define sf scanf
#define pf printf
#define ms(a, x) memset((a), (x), sizeof(a))
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <vvb> vvvb;
typedef vector <vvvb> vvvvb;
typedef long long ll;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <vvl> vvvl;
typedef vector <vvvl> vvvvl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef pair <int, ll> il;
typedef vector <il> vil;
typedef vector <vil> vvil;
typedef pair <ll, int> li;
typedef vector <li> vli;
typedef vector <vli> vvli;
typedef set <int> si;
typedef set <li> sli;
typedef set <il> sil;
typedef vector <string> vs;
typedef vector <vs> vvs;
typedef vector <vvs> vvvs;
typedef map <char, int> mci;
typedef pair <ll, ll> pll;
typedef vector <pll> vll;

int get(int r, int c, int n, int mask){
	vvi a(r, vi(c, 0));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (mask % 2) {
				a[i][j] = 1;
			}
			mask /= 2;
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			n -= a[i][j];
		}
	}
	if (n) {
		return (int)1e9;
	}
	int ans = 0;
	int dx[4] = {1, 0};
	int dy[4] = {0, 1};
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			for (int d = 0; d < 2; ++d) {
				if (i + dx[d] < r && j + dy[d] < c && a[i][j] && a[i + dx[d]][j + dy[d]]) {
					ans++;
				}
			}
		}
	}
	return ans;
}

void solve() {
	int n, r, c;
	cin >> r >> c >> n;
	int ans = (int)1e9;
	for (int mask = 0; mask < (1 << (r * c)); ++mask) {
		ans = min(ans, get(r, c, n, mask));
	}
	if (ans == (int)1e9) {
		throw 1;
	}
	cout << ans << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
		solve();
	}
}
