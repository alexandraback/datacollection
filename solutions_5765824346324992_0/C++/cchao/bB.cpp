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
		int b, n; rii(b, n);
		ria(a, b);
		if(n <= b) {
			printf("Case #%d: %d\n", ks, n);
			continue;
		}
		n -= b;
		ll l = 0, r = 1000000000LL * 100000LL + 10;
		ll ans = 0;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			ll cnt = 0;
			rep(i, b) cnt += mid / a[i];
			if(cnt >= n) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
				ans = mid;
			}
		}
		ll cnt = n;
		rep(i, b) cnt -= ans / a[i];
//		printf("ans %lld %lld\n", ans, cnt);
		int no = 0;
		rep(i, b) {
			if(ans % a[i] == a[i] - 1) {
				cnt--;
				if(cnt == 0) {
					no = i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", ks, no + 1);
	}
	return 0;
}

