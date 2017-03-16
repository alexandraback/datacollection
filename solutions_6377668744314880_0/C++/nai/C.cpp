#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cctype>
#include <complex>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

#define pr(x) do{cout << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cout << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)
#define pra(x,n) rep(__i,n) pri(x,__i);
#define prar(x,b,e) repr(__i,b,e) pri(x,__i);

typedef long long llint;
//const int INF = 1001001001;
const llint INFll = 9008007006005004003ll;

typedef pair<int, int> pint;
typedef vector<int> vint;



const double EPS = 1e-8;
const double INF = 1e12;
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

vector<P> convex_hull(vector<P> &ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) == -1) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) == -1) --k;
  ch.resize(k-1);
  return ch;
}

int in() {
	int a;
	scanf("%d ", &a);
	return a;
}

int main() {
	int T = in();
	for (int t = 0; t < T; t++) {
		//pr(t);
		int N = in();
		vector<P> data(N);
		rep(i,N) {
			int x = in();
			int y = in();
			data[i] = P(x, y);
		}
		
		printf("Case #%d:\n", t+1);
		for (int tt = 0; tt < N; tt++) {
			int ans = N - 1;
			for (int i = 0; i < (1 << N); i++) {
				vector<P> ps;
				int count = 0;
				for (int k = 0; k < N; k++) {
					if ((1 << k) & i) {
						ps.pb(data[k]);
						count++;
					}
				}
				if (N - count > ans) continue;
				
				vector<P> ch = convex_hull(ps);
				bool ok = false;
				rep(k, ch.size()) {
					if (ch[k] == data[tt]) {
						ok = true;
						break;
					}
				}
				if (ok) ans = N - count;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
