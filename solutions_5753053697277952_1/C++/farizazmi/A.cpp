#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int n, p[N];

int getVal() {
  int ret = -1, id = -1;
  for (int i = 0; i < n; i++)
    if (ret < p[i])
      ret = p[i], id = i;
  return id;
}

bool isValid() {
  int ret = -1, tot = 0;
  for (int i = 0; i < n; i++)
    tot += p[i], ret = max(ret, p[i]);
  return (ret * 2 <= tot);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    printf("Case #%d:", tc);
    scanf("%d", &n);
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; i++)
      scanf("%d", &p[i]);
    int tot = 0;
    for (int i = 0; i < n; i++)
      tot += p[i];
    for (int i = 0; i < tot; i++) {
      int id = getVal();
      p[id]--;
      printf(" %c", (char) ('A' + id));
      if (!isValid()) {
        int it = getVal();
        p[it]--, i++;
        printf("%c", (char) ('A' + it));
      }
    }
    puts("");
  }
  return 0;
}