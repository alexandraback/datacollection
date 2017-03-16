#include "cstdio"
#include "iostream"
#include "algorithm"

using namespace std;

int a[ 102 ];

int main() {
  int ntc;

  cin >> ntc;
  for (int tc = 1; tc <= ntc; tc++) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0;
    int mx = 0;
    for (int i = 1; i < n; i++) {
      ans += max(0, a[i - 1] - a[i]);
      mx = max( mx, a[i - 1] - a[i] );
    }

    int ans2 = 0;
    for (int i = 0; i < n - 1; i++) {
      ans2 += min( mx, a[i] );
    }
    
    printf("Case #%d: %d %d\n", tc, ans, ans2);
  }

  return 0;
}
