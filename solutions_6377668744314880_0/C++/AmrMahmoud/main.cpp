#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <utility>
#include <iomanip>
#include <set>
#include <numeric>
#include <cassert>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))

using namespace std;

#include <complex>

typedef complex<double> point;

#define x real()
#define y imag()
#define polar(r, t) (r * exp(point(0, t)))
#define length(a) hypot(a.X, a.Y)
#define angle(a) atan2(a.Y, a.X)
#define vec(a, b) (b - a)
#define dot(a, b) ((conj(a) * b).x)
#define cross(a, b) ((conj(a) * b).y)
#define lengthsqr(a) dot(a, a)
#define vec_rot(v, t) (v * exp(point(0, t)))
#define vec_rot_around(v, t, a) (vec_rot(vec(a, v), t) + a)
#define reflect(v, m) (conj(v / m) * m)

LL crosss(const point &O, const point &A, const point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<pair<point, int> > convex_hull(vector<pair<point, int> > P)
{
	int n = P.size(), k = 0;
	vector<pair<point, int> > H(2*n);
 	for(int i = 0; i < n; ++i) {
		while (k >= 2 && crosss(H[k-2].f, H[k-1].f, P[i].f) <= 0) k--;
		H[k++] = P[i];
	}
 	for(int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && crosss(H[k-2].f, H[k-1].f, P[i].f) <= 0) k--;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}

bool point_on_ray(const point &a, const point &b, const point &p)
{
  return fabs(cross(vec(a, b), vec(a, p))) < EPS && dot(vec(a, b), vec(a, p)) > -EPS;
}

bool sorter(pair<point, int> a, pair<point, int> b)
{
  if(a.f.x == b.f.x) return a.f.y < b.f.y;
  return a.f.x < b.f.x;
}

bool point_on_segment(const point &a, const point &b, const point &p)
{
  if(lengthsqr(vec(a, b)) < EPS)
      return lengthsqr(vec(a, p)) < EPS;
  return point_on_ray(a, b, p) && point_on_ray(b, a, p);
}

int res[105];

int main()
{
  ios_base::sync_with_stdio(0);
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("out.out", "w", stdout);
  int t, tt = 1;
  cin >> t;
  while(t--)
  {
    int n, a, b;
    cin >> n;
    vector<pair<point, int> > v;
    for(int i=0;i<n;i++)
    {
      cin >> a >> b;
      v.pb(mp(point(a, b), i));
      res[i] = INF;
    }
    sort(v.begin(), v.end(), sorter);
    for(int i=1;i<(1 << n);i++)
    {
      vector<pair<point, int> > tmp;
      for(int j=0;j<n;j++)
        if(i & (1 << j))
          tmp.pb(v[j]);
      tmp = convex_hull(tmp);
      for(int j=0;j<n;j++)
      {
        if(res[v[j].s] < n - __builtin_popcount(i)) continue;
        bool test = 0;
        for(int k=0;k<tmp.size() && !test;k++)
          if(point_on_segment(tmp[k].f, tmp[(k + 1) % (tmp.size())].f, v[j].f))
            test = true;
        if(test) res[v[j].s] = n - __builtin_popcount(i);
      }
    }
    cout << "Case #" << tt++ << ": " << "\n";
    for(int i=0;i<n;i++)
      cout << res[i] << "\n";
  }
  return 0;
}
