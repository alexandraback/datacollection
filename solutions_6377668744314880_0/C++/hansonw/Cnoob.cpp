#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define X first
#define Y second

typedef pair<int,int> pii;
typedef long long ll;
pair<pii, int> points[4000];

pii operator-(const pii& a, const pii& b) {
  return make_pair(a.first - b.first, a.second - b.second);
}

bool ok(const pii& a, const pii& b, const pii& c) {
  pii x = b - a, y = c - b;
  // (+1, +1) * (+2, +0) = -2
  ll cprod = ll(x.X) * y.Y- ll(x.Y) * y.X;
  return cprod <= 0;
}

set<int> hull(vector<pair<pii, int> > points) {
  set<int> result;
  int N = points.size();
  vector<pair<pii, int> > hull;
  for (int i = 0; i < N; i++) {
    if (hull.size() < 2) {
      hull.push_back(points[i]);
      continue;
    }
    // can we add this point?
    for (int j = hull.size()-1; j >= 0; j--) {
      if (j == 0 || ok(hull[j-1].X, hull[j].X, points[i].X)) {
        hull.erase(hull.begin() + j + 1, hull.end());
        hull.push_back(points[i]);
        break;
      }
    }
  }

  for (int i = 0; i < hull.size(); i++) {
    result.insert(hull[i].Y);
  }

  hull.clear();
  for (int i = N-1; i >= 0; i--) {
    if (hull.size() < 2) {
      hull.push_back(points[i]);
      continue;
    }
    // can we add this point?
    for (int j = hull.size()-1; j >= 0; j--) {
      if (j == 0 || ok(hull[j-1].X, hull[j].X, points[i].X)) {
        hull.erase(hull.begin() + j + 1, hull.end());
        hull.push_back(points[i]);
        break;
      }
    }
  }

  for (int i = 0; i < hull.size(); i++) {
    result.insert(hull[i].Y);
  }
  return result;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> points[i].first.X >> points[i].first.Y;
      points[i].second = i;
    }
    sort(points, points+N);
    vector<int> ans(N, N+1);
    for (int i = 1; i < (1<<N); i++) {
      vector<pair<pii, int>> np;
      for (int j = 0; j < N; j++) {
        if (i & (1<<j)) {
          np.push_back(points[j]);
        }
      }
      set<int> res = hull(np);
      for (auto x : res) {
        ans[x] = min(ans[x], int(N - np.size()));
      }
    }

    printf("Case #%d:\n", t);
    for (int x : ans) {
      cout << x << endl;
    }
  }
}
