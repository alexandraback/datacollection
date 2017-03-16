#include <bits/stdc++.h>
using namespace std;

int m[100000];

int main() {
  int test; scanf("%d", &test);
  for (int cas = 1; cas <= test; ++cas) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", m + i);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n - 1; ++i)
      if (m[i] > m[i + 1])
        ans1 += m[i] - m[i + 1];
    int m1 = 0;
    for (int i = 0; i < n - 1; ++i)
      if (m1 < m[i] - m[i + 1])
        m1 = m[i] - m[i + 1];
    for (int i = 0; i < n - 1; ++i)
      ans2 += m1 < m[i] ? m1 : m[i];
    printf("Case #%d: %d %d\n", cas, ans1, ans2);
  }
}
