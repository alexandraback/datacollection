#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define PRINT(x...) TRACE(printf(x))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define FU(i, a, b) for(decltype(a) i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)

#define FD(i, a, b) for (decltype(a) i = (b)-1; i >= a; --i)
#define fd(i, n) FD(i, 0, n)

#define mset(c, v) memset(c, v, sizeof(c))
#define mod(a, b) ((((a)%(b))+(b))%(b))
#define pb push_back
#define sz(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-8;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef pair<ll, ll> point;

void getline(point& p1, point& p2, ll& a, ll& b, ll& c) {
	a = p2.second - p1.second;
	b = p1.first - p2.first;
	c = -a*p1.first - b*p1.second;
}

int main() {
	int _42;
	scanf("%d", &_42);
	fu(_41, _42) {
		printf("Case #%d:\n", _41+1);
		int N;
		scanf("%d", &N);
		vector<point> V(N);
		for (auto& x : V) scanf("%lld %lld", &x.first, &x.second);
		if (N == 1) printf("0\n");
		else if (N == 2) printf("0\n0\n");
		else if (N == 3) printf("0\n0\n0\n");
		else fu(i, N) {
			vector<point> V2;
			fu(j, N) if (i != j) V2.pb(V[j]);
			sort(all(V2), [&](const point& lhs, const point& rhs) {
						return atan2(lhs.second - V[i].second, lhs.first - V[i].first) < 
						       atan2(rhs.second - V[i].second, rhs.first - V[i].first);
					});
			int pos = 0;
			int pos2 = 0;
			int count = 0;
			int ans;
			ll a, b, c;
			getline(V[i], V2[0], a, b, c);
			fd(j, N-1) if (a*V2[j].first + b*V2[j].second + c > 0) {
				count++;
				pos2 = j;
			}
			ans = count;
			if (pos2 == 0 || count == 0) ans = 0; // already on the border
			else for(++pos; pos < N-1; ++pos) {
				getline(V[i], V2[pos], a, b, c);
				while (a*V2[pos2].first + b*V2[pos2].second + c <= 0) {
					count--;
					pos2 = (pos2 + 1) % (N-1);
					if (pos2 == pos) break;
				}
				if (pos2 == pos) {ans = 0; break;}
				if (a*V2[pos-1].first + b*V2[pos-1].second + c > 0) count++;
				ans = min(ans, count);
				if (ans == 0) break;
			}

			printf("%d\n", ans);
		}
	}
	return 0;
}
