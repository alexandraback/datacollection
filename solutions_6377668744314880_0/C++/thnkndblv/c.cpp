#include "cstdio"
#include "iostream"
#include <algorithm>
#include <vector>

using namespace std;
 
typedef long long Long;

struct Point {
  Long x, y;
 
  bool operator <(const Point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};
 

Long cross(const Point &O, const Point &A, const Point &B)
{
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> P;

bool cmp(const int &a, const int &b) {
  return P[a] < P[b];
}

vector<int> convex_hull(vector<int> p)
{
  int n = p.size(), k = 0;
  vector<int> H(2*n);
 
  sort(p.begin(), p.end(), cmp);
 
  for (int i = 0; i < n; i++) {
    while (k >= 2 && cross(P[H[k-2]], P[H[k-1]], P[p[i]]) < 0) k--;
    H[k++] = p[i];
  }
 
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && cross(P[H[k-2]], P[H[k-1]], P[p[i]]) < 0) k--;
    H[k++] = p[i];
  }
 
  H.resize(k);
  return H;
}

vector<int> ans;

int main() {
  int ntc;

  cin >> ntc;
  for (int tc = 1; tc <= ntc; tc++) {
    int n;
    cin >> n;
    P.resize( n );
    for (int i = 0; i < n; i++) scanf("%lld %lld", &P[i].x, &P[i].y);

    ans.assign(n, n - 1);
    int N = 1 << n;
    for (int s = 1; s < N; s++) {
      vector<int> pts;
      for (int i = 0; i < n; i++)
        if ( s & (1 << i) )
          pts.push_back( i );
      vector<int> ch = convex_hull( pts );
      int rem = n - __builtin_popcount(s);
      for (int i = 0; i < ch.size(); i++) {
        ans[ ch[i] ] = min( ans[ ch[i] ], rem );
      }
    }

    printf("Case #%d:\n", tc);
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
  }

  return 0;
}