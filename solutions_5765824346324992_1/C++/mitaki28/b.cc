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

const int MAX_N = 1100;

ll n, m;
ll a[MAX_N];

ll ct(ll x) {
  ll r = 0;
  for (int i = 0; i < n; i++) {
    r += x / a[i];
  }
  return r;
}

int main() {
  ll T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (m <= n) {
      cout << m << endl;
      continue;
    }
    m -= n;
    ll ub = 1LL << 60, lb = 0;
    while (ub - lb > 1) {
      ll mid = (ub + lb) / 2;
      if (ct(mid) < m) {
        lb = mid;
      } else {
        ub = mid;
      }
    }
    int r = -1;
    ll rest = m - ct(lb);
    for (int i = 0; i < n; i++) {
      if (ub % a[i] == 0) {
        if (rest == 1) {
          r = i;
          break;
        } else {
          rest--;
        }
      }
    }
    assert(r != -1);
    cout << r + 1 << endl;
  }
}
