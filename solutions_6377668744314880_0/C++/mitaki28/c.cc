#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <limits>
#include <utility>

#include <array>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> Pt;

const ll EPS = 0;

Pt operator-(const Pt &p, const Pt &q) {
  return Pt(p.first - q.first, p.second - q.second);
}


bool operator<(const Pt &p, const Pt &q) {
  return abs(p.first - q.first) > 0 ? (p.first - q.first) < EPS : (p.second - q.second) < 0;
}

ll det(Pt p, Pt q) {
  return p.first * q.second - p.second * q.first;
}

vector<Pt> convex_hull(vector<Pt> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<Pt> qs(2 * n);
  for (int i = 0; i < n; i++) {
    while (k > 1
           && det(qs[k - 1] - qs[k - 2],
                  ps[i] - qs[k - 1]) < 0) k--;
    qs[k++] = ps[i];
  }
  int t = k;
  for (int i = n - 2; i >= 0; i--) {
    while (k > t
           && det(qs[k - 1] - qs[k - 2],
                  ps[i] - qs[k - 1]) < 0) k--;
    qs[k++] = ps[i];
  }
  qs.resize(max(0, k - 1));
  return qs;
}

const int MAX_N = 15;
int n;


int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ":" << endl;
    cin >> n;
    vector<Pt> ps(n);
    for (int i = 0; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      ps[i] = Pt(x, y);
    }
    vector<int> rs(n, n - 1);
    for (int S = 1; S < (1 << n); S++) {
      vector<Pt> ts;
      for (int i = 0; i < n; i++) {
        if (S & (1 << i)) {
          ts.push_back(ps[i]);
        }
      }
      vector<Pt> qs = convex_hull(ts);
      for (Pt p : qs) {
        for (int i = 0; i < n; i++) {
          if (p == ps[i]) {
            rs[i] = min(rs[i], n - __builtin_popcount(S));
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << rs[i] << endl;
    }
  }
}
