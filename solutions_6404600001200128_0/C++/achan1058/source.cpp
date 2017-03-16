#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vb> vvb;
typedef vector<vs> vvs;
typedef vector<vl> vvl;

int inf = 0x3f3f3f3f;
double eps = 10e-10;
ll mod = 1000000007ll;

#define rep(k, a, b) for (int k = (a); k < int(b); k++)
#define sz(a) int(a.size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define x first
#define y second
#define mi(r, c, v) vvi(r, vi(c, v))
#define rrep(k, a, b) for (int k = (a); k >= int(b); k--)
#define irep(k, a) for (auto& k : (a))
#define md(r, c, v) vvd(r, vd(c, v))
#define mb(r, c, v) vvb(r, vb(c, v))
#define ms(r, c, v) vvs(r, vs(c, v))
#define ml(r, c, v) vvl(r, vl(c, v))
#define mc(r, c, v) vs(r, string(c, v))
#define add(i, j) ((i) + (j)) % mod
#define mul(i, j) ((i) * (j)) % mod
#define bits(n) int(__builtin_popcount(n))

int main() {
	int T, n;
	cin >> T;
	rep(X, 0, T) {
		cin >> n;
		vi mush(n);
		int total = 0, mx = 0, total2 = 0;
		irep(v, mush)
			cin >> v;
		rep(i, 0, n - 1) {
			if (mush[i + 1] < mush[i]) {
				total += mush[i] - mush[i + 1];
				mx = max(mx, mush[i] - mush[i + 1]);
			}
		}

		rep(i, 0, n - 1) {
			if (mush[i] < mx)
				total2 += mush[i];
			else
				total2 += mx;
		}

		printf("Case #%d: %d %d\n", X + 1, total, total2);
	}
}
