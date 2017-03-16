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

ll n;
ll a[MAX_N];

int main() {
  ll T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll s1 = 0, s2 = 0;
    ll v = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) { 
        s1 += a[i] - a[i + 1];
        v = max(v, a[i] - a[i + 1]);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      s2 += min(v, a[i]);
    }
    cout << s1 << ' ' << s2 << endl;
  }
}
