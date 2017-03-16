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

int main() {
  std::ios_base::sync_with_stdio(false);
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int res0 = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] < a[i - 1]) {
        res0 += a[i - 1] - a[i];
      }
    }
    int d = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] < a[i - 1] && d < a[i - 1] - a[i]) {
        d = a[i - 1] - a[i];
      }
    }
    int res1 = 0;
    for (int i = 0; i + 1 < n; ++i) {
      res1 += min(d, a[i]);  
    }
    PrintTestCase(test_index + 1); 
    cout << res0 << ' ' << res1 << "\n"; 
  }
  return 0;
}
