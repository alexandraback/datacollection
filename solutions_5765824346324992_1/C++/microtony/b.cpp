#include <bits/stdc++.h>
using namespace std;
int a[10005], n, q;
long long check(long long t) {
  if (t == -1) return 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += t / a[i] + 1;
  }
  return sum;
}
int solve() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  long long hi = 1LL<<54;
  long long lo = 0;
  while (hi - lo > 2) {
    long long mid = (hi + lo) / 2;
    if (check(mid) >= q) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  long long last = check(lo - 1);
  //printf("lo = %lld last = %lld\n", lo, last);
  for (long long t = lo; t < lo + 6; t++) {
    for (int i = 0; i < n; i++) {
      if (t % a[i] == 0) {
        last++;
        if (last == q) {
          return i;
        }
      }
    }
  }
  return -999;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int caseno = 1; caseno <= t; caseno++) {
    printf("Case #%d: %d\n", caseno, solve() + 1);
  }
  return 0;
}

