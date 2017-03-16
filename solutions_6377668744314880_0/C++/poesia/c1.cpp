#include <iostream>
#include <cmath>
#include <map>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

int cmpf(double a, double b = 0) {
  a -= b;
  return a > EPS ? 1 : a < -EPS ? -1 : 0;
}

typedef long long coord_type; //ou double

struct point {
  coord_type x, y; //dependendo do problema, use int
  point(coord_type x = 0, coord_type y = 0) : x(x), y(y) { }
  double dist(const point& o) const {
    return sqrt(pow(x - o.x, 2) + pow(y - o.y, 2));
  }
  coord_type cross(const point& o) const {
    return x * o.y - y * o.x;
  }
  bool operator==(const point &o) const {
    return !(cmpf(x, o.x) || cmpf(y, o.y));
  }
  bool operator!=(const point &o) const {
    return cmpf(x, o.x) || cmpf(y, o.y);
  }
  point operator-(const point &o) const {
    return point(x - o.x, y - o.y);
  }
  point operator+(const point &o) const {
    return point(x + o.x, y + o.y);
  }
  point operator/(double d) const {
    return point(x/d, y/d);
  }
  bool operator<(const point &o) const {
    return x < o.x || (x == o.x && y < o.y);
  }
};

ostream& operator<<(ostream& o, point p) {
  return o << "(" << p.x << ", " << p.y << ")";
}

void monotone_chain(vector<point>& pts, vector<int>& hull) {
  sort(pts.begin(), pts.end());
  hull.resize(pts.size()+200);
  int k = -1, k2;

  for(int i = 0; i < pts.size(); i++) {// >= abaixo - remover pontos colineares
    while(k > 0 && (pts[hull[k]] - pts[hull[k-1]]).cross(pts[i] - pts[hull[k]]) > 0)
      k--;
    hull[++k] = i;
  }
  k2 = k;
  for(int i = pts.size()-1; i >= 0; i--) { // >= abaixo - remover pontos colineares
    while(k2 > k && (pts[hull[k2]] - pts[hull[k2-1]]).cross(pts[i] - pts[hull[k2]]) > 0)
      k2--;
    hull[++k2] = i;
  }

  hull.resize(k2);//+1 para duplicar o primeiro ponto
}

typedef vector<point> polygon;

const int MAXN = 16;

int dp[1 << MAXN];
int hull[1 << MAXN];
int n;

int doit(int ss, int x) {
  if (dp[ss] == -1) {
    if (hull[ss] & (1 << x)) {
      dp[ss] = 0;
    } else {
      dp[ss] = MAXN;
      for (int i = 0; i < n; i++) {
        if (ss & (1 << i) && (i != x)) {
          dp[ss] = min(dp[ss], 1 + doit(ss ^ (1 << i), x));
        }
      }
    }
  }
  return dp[ss];
}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> n;

    vector<point> v(n);
    map<point, int> idx;

    for (int i = 0; i < n; i++) {
      cin >> v[i].x >> v[i].y;
      idx[v[i]] = i;
    }

    for (int ss = 1; ss < (1 << n); ss++) {
      vector<point> pts;
      vector<int> is;

      for (int j = 0; j < n; j++)
        if (ss & (1 << j)) {
          pts.push_back(v[j]);
        }

      vector<int> h;

//      cerr << "mc [";

//      for (int i = 0; i < pts.size(); i++)
//        cerr << pts[i] << " ";

      monotone_chain(pts, h);

/*      cerr << "] = [";

      for (int i = 0; i < h.size(); i++)
        cerr << pts[h[i]] << " ";

      cerr << "]\n"; */

      hull[ss] = 0;
      for (int i = 0; i < h.size(); i++)
        hull[ss] |= 1 << idx[pts[h[i]]];
//      cerr << "hull[" << bitset<15>(ss) << "] = " << bitset<15>(hull[ss]) << endl;
    }

    cout << "Case #" << t << ":\n";

    for (int i = 0; i < n; i++) {
      memset(dp, -1, sizeof dp);
      cout << doit((1 << n) - 1, i) << '\n';
    }
  }

  return 0;
}
