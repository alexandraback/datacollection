#include <bits/stdc++.h>
using namespace std;

#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define FOREACH(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) { return (a < b) ? a : b; }
template<class T, class U> inline T tmax(T a, U b) { return (a > b) ? a : b; }
template<class T, class U> inline void amax(T &a, U b) { if (b > a) a = b; }
template<class T, class U> inline void amin(T &a, U b) { if (b < a) a = b; }
template<class T> inline T tabs(T a) { return (a > 0) ? a : -a; }
template<class T> T gcd(T a, T b) { while (b != 0) { T c = a; a = b; b = c % b; } return a; }

typedef pair<int, char> P;
#define X first
#define Y second

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
	int nTest, n, p;

	cin >> nTest;
	REPU(it, 1, nTest + 1) {
		cin >> n;
		printf("Case #%d:", it);
		int tot = 0;
		vector<P> a(n);
		REPU(i, 0, n) {
			cin >> p;
			tot += p, a[i] = P(p, i + 'A');
		}
		while (tot > 0) {
			sort(ALL(a));
			if (2 * a[n - 1].X > tot) {
				assert(0);
			}
			if (a[n - 1].X >= 2 && 2 * a[n - 2].X <= tot - 2) {
				a[n - 1].X -= 2, tot -= 2;
				printf(" %c%c", a[n - 1].Y, a[n - 1].Y);
				continue;
			}
			else if (2 * max(a[n - 2].X, a[n - 1].X - 1) <= tot - 1) {
				a[n - 1].X -= 1, tot -= 1;
				printf(" %c", a[n - 1].Y);
				continue;
			}
			else {
				assert(a[n - 2].X > 0);
				a[n - 1].X -= 1, a[n - 2].X -= 1, tot -= 2;
				printf(" %c%c", a[n - 1].Y, a[n - 2].Y);
				continue;
			}
			assert(0);
		}
		puts("");
	}
	
	return 0;
}
