#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char dic[100][101], fuck[100][101];
int fuck_top[100], cnt[100][101], tmp[101];
int n;

void solve(int cas) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", dic[i]);
    fuck_top[i] = 0;
    for (int j = 0; dic[i][j] != 0; j++) {
      if (fuck_top[i] == 0 || dic[i][j] != fuck[i][fuck_top[i] - 1]) {
        cnt[i][fuck_top[i]] = 0;
        fuck[i][fuck_top[i]++] = dic[i][j];
      } else {
        cnt[i][fuck_top[i] - 1]++;
      }
      fuck[i][fuck_top[i]] = 0;
    }
  }

  printf("Case #%d: ", cas);
  for (int i = 0; i < n; i++) {
    if (strcmp(fuck[i], fuck[0]) != 0) {
      printf("Fegla Won\n");
      return;
    }
  }

  int ans = 0;
  for (int i = 0; i < fuck_top[0]; i++) {
    for (int j = 0; j < n; j++) {
      tmp[j] = cnt[j][i];
    }
    nth_element(tmp, tmp + n / 2, tmp + n);
    for (int j = 0; j < n; j++) {
      ans += abs(tmp[j] - tmp[n / 2]);
    }
  }

  printf("%d\n", ans);
}

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  int totCas;
  scanf("%d", &totCas);
  for (int cas = 1; cas <= totCas; cas++) {
    solve(cas);
  }
  return 0;
}

