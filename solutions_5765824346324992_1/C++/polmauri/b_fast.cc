#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef pair<ll, int> P;

const ll INF = 1000000000000000000LL;

ll satisfied(ll t, const Vi& v) {
  int n = v.size();
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += t/v[i] + 1;
  }
  return res;
}

int compute(ll p, const Vi& v) {
  ll e = 0;
  ll d = INF;
  ll r = INF;
  while (e <= d) {
    ll t = (e + d)/2;
    if (satisfied(t, v) <= p) {
      e = t + 1;
    }
    else {
      r = t;
      d = t - 1;
    }
  }
  ll s = satisfied(r, v);
  int n = v.size();
  for (int i = n - 1; i >= 0; --i) {
    if (r%v[i] == 0) {
      --s;
      if (s == p) {
        return i;
      }
    }
  }
  return -1;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int b, n;
    cin >> b >> n;
    Vi v(b);
    for (int i = 0; i < b; ++i) {
      cin >> v[i];
    }
    cout << "Case #" << cas << ": " << compute(n - 1, v) + 1 << endl;
  }
}
