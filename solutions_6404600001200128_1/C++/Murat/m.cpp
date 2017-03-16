#include<bits/stdc++.h>
  
using namespace std;

template<class T> inline T sqr(const T& a) { return a * a; }
  
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
  
constexpr ld EPS = 1e-9;
constexpr ld PI = 2 * acos(0.0);
constexpr int N = 100;

int main() {
  int ts;
  scanf("%d", &ts);
  for (int it = 1; it <= ts; ++it) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    int ans1 = 0;
    int maxdif = 0;
    for (int i = 1; i < n; ++i)
      if (a[i] < a[i - 1]) {
        ans1 += a[i - 1] - a[i];
        maxdif = max(maxdif, a[i - 1] - a[i]);
      }
    int ans2 = 0;
    for (int i = 0; i + 1 < n; ++i) {
      ans2 += min(a[i], maxdif);
    }
    printf("Case #%d: %d %d\n", it, ans1, ans2);
  }
  return 0;
}
