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
		vvi ans(N, vi(N, 1000000));
		fu(i, N) fu(j, i) {
			ll a, b, c;
			getline(V[i], V[j], a, b, c);
			int c1 = 0, c2 = 0;
			fu(k, N) {
				ll tmp = a*V[k].first + b*V[k].second + c;
				if (tmp > 0) c1++;
				else if (tmp < 0) c2++;
			}
			ans[i][j] = ans[j][i] = min(c1, c2);
		}
		if (N == 1) printf("0\n");
		else fu(i, N) printf("%d\n", *min_element(all(ans[i])));
	}
	return 0;
}
