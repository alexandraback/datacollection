#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e3+10;

int n,x[N];

inline void solve () {
  scanf ("%d", &n);
  for (int i = 0;i < n;i ++) {
    scanf ("%d", &x[i]);
  }

  int ans1 = 0,k = 0;
  for (int i = 1;i < n;i ++) {
    if (x[i] < x[i-1]) {
      ans1 += x[i-1]-x[i];
      k = max (k, x[i-1]-x[i]);
    }
  }

  int ans2 = 0;
  for (int i = 0;i < n-1;i ++) {
    ans2 += min (x[i], k);
  }

  printf ("%d %d\n", ans1, ans2);
}

int main () {
  int t;
  scanf ("%d", &t);

  for (int i = 1;i <= t;i ++) {
    printf ("Case #%d: ", i);
    solve ();
  }
}
