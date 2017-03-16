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

int a[1010];
int main() {
	CASE {
		int n; ri(n);
		int y = 0, z = 0, gap = 0;
		ria(a, n);
		rep(i, n) {
			if(i && a[i] < a[i-1]) {
				y += a[i-1] - a[i];
				gap = max(gap, a[i-1] - a[i]);
			}
		}
		rep(i, n - 1) {
			z += min(gap, a[i]);
		}
		printf("Case #%d: %d %d\n", ks, y, z);
	}
	return 0;
}

