#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> Vi;
typedef vector<P> Vp;

bool sortf(P a, P b) {
  return atan2(a.second, a.first) < atan2(b.second, b.first);
}

ll cross(P a, P b, P c) {
  return (c.first - b.first)*(a.second - b.second) -
         (c.second - b.second)*(a.first - b.first);
}

int compute_single_at_origin(Vp& v) {
  sort(v.begin(), v.end(), sortf);
  int n = v.size();
  int j = 0;
  int res = n;
  for (int i = 0; i < n; ++i) {
    j = max(j, i + 1);
    while (cross(v[j%n], P(0, 0), v[i]) > 0) {
      ++j;
    }
    res = min(res, j - i - 1);
  }
  return res;
}

void compute_all(const Vp& v, Vi& res) {
  int n = v.size();
  res = Vi(n);
  for (int i = 0; i < n; ++i) {
    Vp u;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        u.push_back(P(v[j].first - v[i].first, v[j].second - v[i].second));
      }
    }
    res[i] = compute_single_at_origin(u);
  }
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int n;
    cin >> n;
    Vp v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first >> v[i].second;
    }
    Vi res;
    compute_all(v, res);
    cout << "Case #" << cas << ":" << endl;
    for (int i = 0; i < n; ++i) {
      cout << res[i] << endl;
    }
  }
}
