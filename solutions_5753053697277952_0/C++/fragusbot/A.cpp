#include <bits/stdc++.h>

using namespace std;

int a[26];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  freopen("log", "w", stderr);
  int tt;
  scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    printf("Case #%d: ", cc);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    vector <string> ans;
    while (true) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
          ++cnt;
        }
      }
      if (cnt == 0) {
        break;
      }
      if (cnt != 2) {
        int j = 0;
        for (int i = 0; i < n; ++i) {
          if (a[i] > a[j]) {
            j = i;
          }
        }
        --a[j];
        string cur = "";
        cur += 'A' + j;
        ans.push_back(cur);
      } else {
        string cur = "";
        for (int i = 0; i < n; ++i) {
          if (a[i] != 0) {
            --a[i];
            cur += 'A' + i;
          }
        }
        ans.push_back(cur);
      }
    }
    for (int i = 0; i < ans.size(); ++i) {
      if (i > 0) {
        printf(" ");
      }
      printf("%s", ans[i].c_str());
    }
    printf("\n");
  }
  return 0;
}