#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef complex<double> cd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rd(a) scanf("%lf", &a)
#define rs(a) scanf("%s", s)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ria(a, n) rep(_, n) ri(a[_])
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define pi(x) printf("%d\n", x)
#define PB push_back
#define SZ(X) ((int)X.size())
#define ALL(X) X.begin(), X.end()
#define fst first
#define snd second
#define Ttimes int T; scanf("%d", &T); while(T--)
#define CASE  int T; scanf("%d", &T); for(int ks = 1; ks <= T; ++ks)
// printf("Case #%d: %d\n", ks, ans);
int dcmp(double x) { return fabs(x) < 1e-8 ? 0 : (x < 0 ? -1 : 1); }
double dot(cd a, cd b) { return real(conj(a)*b); }
double cross(cd a, cd b) { return imag(conj(a)*b); }
bool cmp(const cd &a, const cd &b) {
	return make_pair(a.real(), a.imag()) < make_pair(b.real(), b.imag());
}
vector<cd> ConvexHull(vector<cd> p) {
	sort(p.begin(), p.end(), cmp);
	int n = p.size();
	int m = 0;
	vector<cd> ch(n+n);
	for(int i = 0; i < n; i++) {
		while(m > 1 && cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2; i >= 0; i--) {
		while(m > k && cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
		ch[m++] = p[i];
	}
	if(n > 1) m--;
	ch.resize(m);
	return ch;
}

int x[3010], y[3010], a[3010], ans[3010];
double ag[6020];

const double pi = acos(-1);

int main() {
	CASE {
		int n; ri(n);
		rep(i, n) {
			rii(x[i], y[i]);
			ans[i] = n - 1;
		}

		rep(i, n) {
			int sz = 0;
			rep(j, n) if(j != i) {
				ag[sz++] = atan2(y[j] - y[i], x[j] - x[i]);
			}
			sort(ag, ag + sz);
			for(int j = sz; j < sz + sz; j++) ag[j] = ag[j-sz] + pi + pi;
//			pi(i);
			sz <<= 1;
//			rep(j, sz) printf("angle - %f\n", ag[j]);
			int from = 0;
			for(int j = 1; j < sz; ++j) {
				while(ag[j] - ag[from] > pi || j - from + 1 > n - 1) from++;
				ans[i] = min(ans[i], (n - 1) - (j - from + 1));
			}
		}


		printf("Case #%d:\n", ks);
		rep(i, n) {
			printf("%d\n", ans[i]);
		}

	}
	return 0;
}
