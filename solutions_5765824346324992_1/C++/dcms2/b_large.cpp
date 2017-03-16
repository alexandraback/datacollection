#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

int m[1005];

int main() {
  int nt; scanf("%d", &nt);
  for (int _ = 1; _ <= nt; ++_) {
    int b, n; scanf("%d %d", &b, &n);
    for (int i = 0; i < b; ++i) {
      scanf("%d", &m[i]);
    }
    int ans = -1;
    if (n <= b) {
      ans = n; goto lol;
    }
    for (int i = 0; i < b; ++i) {
      ll lo = 1, hi = 1000000000LL;
      while (lo <= hi) {
        ll mid = (lo + hi)/2;
        ll qnt = b;
        for (int j = 0; j <= i; ++j) {
          qnt += (m[i] * mid) / m[j];
        }
        for (int j = i+1; j < b; ++j) {
          qnt += max(0LL, ((m[i]*mid+m[j]-1)/ m[j]) - 1);
        }
        if (qnt > n) hi = mid - 1;
        else if (qnt == n) { ans = i + 1; goto lol; }
        else lo = mid + 1;
      }
    }
    lol:;
    printf("Case #%d: %d\n", _, ans);
    fprintf(stderr, "case %d finished\n", _);
  }
  return 0;
}