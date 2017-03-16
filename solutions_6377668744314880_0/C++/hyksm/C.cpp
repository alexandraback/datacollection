#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <climits>
#include <cfloat>
#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <queue>
#include <complex>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const double EPS = 0.0000000001;
const long long int INF = 1000000000;

typedef complex<double> P;
namespace std {
	bool operator < (const P& a, const P& b) {
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
double cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
	return real(conj(a)*b);
}

struct L : public vector<P> {
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};

typedef vector<P> G;

struct C {
	P p; double r;
	C(const P &p, double r) : p(p), r(r) { }
};

int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;       // counter clockwise
	if (cross(b, c) < 0)   return -1;       // clockwise
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}

int N;
P points[3000];

void solve()
{
	if (N == 1) {
		printf("0\n");
		return;
	}

	for (int i = 0; i < N; ++i) {
		int res = N;
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;

			int a = 0, b = 0;
			for (int k = 0; k < N; ++k) {
				if (i == k || j == k) continue;
				int ccw_ = ccw(points[i], points[j], points[k]);
				if (ccw_ == 1) ++a;
				else if (ccw_ == -1) ++b;
			}
			res = min(res, min(a, b));
		}
		printf("%d\n", res);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int c = 0; c < T; ++c) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			points[i].real(x);
			points[i].imag(y);
		}
		printf("Case #%d:\n", c + 1);
		solve();
	}

	return 0;
}

