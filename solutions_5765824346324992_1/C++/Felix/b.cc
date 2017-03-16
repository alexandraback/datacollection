#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define DEBUG(x) cerr << #x << " = " << x << endl

#define FR first
#define SC second

using namespace std;

typedef long long ll;
typedef long double ld;

template <class Ta, class Tb> inline Tb cast(Ta a) {
  stringstream ss;
  ss << a;
  Tb b;
  ss >> b;
  return b;
};

ll finished(const vector<ll>& m, ll t) {
  ll ret = 0;
  for (int i = 0; i < int(m.size()); ++i) {
    ret += t / m[i];
  }
  return ret;
}

ll freed(const vector<ll>& m, ll t) {
  ll ret = 0;
  for (int i = 0; i < int(m.size()); ++i) {
    if (t % m[i] == 0) ++ret;
  }
  return ret;
}

int solve(const vector<ll>& m, ll n) {
  ll b = ll(m.size());
  ll lo = -1, hi = n * m[0];  // (n - 1) * m[0] should be enough.
  for (; hi - lo > 1;) {
    ll t = lo + (hi - lo) / 2;
    ll finished_t = finished(m, t);
    if (finished_t + b >= n) {
      hi = t;
    }
    else {
      lo = t;
    }
  }
  ll before = n - (finished(m, hi) + b - freed(m, hi) + 1);
  for (int i = 0; i < int(m.size()); ++i) {
    if (hi % m[i] == 0) {
      if (before == 0) return i;
      --before;
    }
  }
  return -1;  // Should never happen.
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    ll b, n;
    cin >> b >> n;
    vector<ll> m(b);
    for (int i = 0; i < int(m.size()); ++i) {
      cin >> m[i];
    }
    cout << "Case #" << ca << ": " << 1 + solve(m, n) << endl;
  }
}

