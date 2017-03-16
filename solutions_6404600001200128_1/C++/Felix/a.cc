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

ll solve_1(const vector<ll>& m) {
  int n = int(m.size());
  ll ret = 0;
  for (int i = 1; i < n; ++i) {
    if (m[i] < m[i - 1]) {
      ret += m[i - 1] - m[i];
    }
  }
  return ret;
}

ll solve_2(const vector<ll>& m) {
  int n = int(m.size());
  ll rate = 0;
  for (int i = 1; i < n; ++i) {
    if (m[i] < m[i - 1]) {
      if (m[i - 1] - m[i] > rate) {
        rate = m[i - 1] - m[i];
      }
    }
  }
  ll ret = 0;
  for (int i = 0; i < n - 1; ++i) {
    ret += min(rate, m[i]);
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    int n;
    cin >> n;
    vector<ll> m(n);
    for (int i = 0; i < n; ++i) {
      cin >> m[i];
    }
    ll y = solve_1(m);
    ll z = solve_2(m);
    cout << "Case #" << ca << ": " << y << " " << z << endl;
  }
}

