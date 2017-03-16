#include <bits/stdc++.h>

using namespace std;

int n, p[30];

bool clear() {
  return *max_element(p,p+n) == 0;
}

bool ok() {
  int s = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    s += p[i];
    mx = max(mx, p[i]);
  }
  return mx*2 <= s;
}

int mostCommon() {
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] > p[r]) r = i;
  }
  return r;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  while (!clear()) {
    int mc1 = mostCommon();
    p[mc1]--;
    if (ok()) {
      printf("%c ", 'A'+mc1);
    }
    else {
      int mc2 = mostCommon();
      p[mc2]--;
      printf("%c%c ", 'A'+mc1, 'A'+mc2);
    }
  }
  printf("\n");
}

int main() {
  int t; scanf("%d", &t);
  for (int ct = 1; ct <= t; ct++) {
    printf("Case #%d: ", ct);
    solve();
  }
  return 0;
}
