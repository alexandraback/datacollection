#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void PrintTestCase(int test_index) {
  cout << "Case #" << test_index << ": ";
}

ll Time(const vector<int>& t, int k) {
  ll l = 0;
  ll r = (ll)1000 * 1000 * 1000 * 1000 * 1000;
  int n = t.size();
  while (l < r) {
    ll cnt = 0;
    ll m = (l + r + 1) >> 1;
    for (int i = 0; i < n; ++i) {
      cnt += (m + t[i] - 1) / t[i]; 
    }
    if (cnt > k) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  return l;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
    }
    ll tm = Time(t, k - 1);
    ll q = 0;
    for (int i = 0; i < n; ++i) {
      q += (tm + t[i] - 1) / t[i];
    }
    int res = -1;
    for (int i = 0; q < k; ++i) {
      if (tm % t[i] == 0) {
        res = i + 1;
        ++q;
      }
    }
    PrintTestCase(test_index + 1); 
    cout << res << "\n";
  }
  return 0;
}
