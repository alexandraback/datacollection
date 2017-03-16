#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char s[105][105];
char t[105];
int cnt[105][105];
int tn;

bool f() {
  for (int i = 1; i < n; ++i) {
    int pn = 0;
    for (int j = 1; s[i][j]; ++j) {
      if (s[i][j] != s[i][j - 1]) {
        if (s[i][j] != t[pn++]) return 0;
      }
      ++cnt[i][pn-1];
    }
    if (tn != pn) return 0;
  }
  return 1;
}

int g() {
  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < tn; ++j) {
      printf("%d ", cnt[i][j]);
    } puts("");
  }
  */
  int ret = 0;
  for (int i = 0; i < tn; ++i) {
    int mn = 1 << 28;
    for (int k = 0; k <= 100; ++k) {
      int sum = 0;
      for (int j = 0 ; j < n; ++j) {
        sum += abs(cnt[j][i] - k);
      }
      if (sum < mn) mn = sum;
    }
    //printf("%d\n", mn);
    ret += mn;
  }
  return ret;
}

int main() {
  int T, cas = 0;
  scanf("%d", &T);
  while (T--) {
    memset(s, 0, sizeof(s));
    memset(cnt, 0, sizeof(cnt));
    memset(t, 0, sizeof(t));
    scanf("%d", &n);
    gets(s[0] + 1);
    for (int i = 0; i < n; ++i) scanf("%s", s[i] + 1);
    tn = 0; t[0] = 0;
    for (int j = 1; s[0][j]; ++j) {
      if (s[0][j] != s[0][j - 1]) {
        t[tn++] = s[0][j];
      }
      ++cnt[0][tn-1];
    }
    printf("Case #%d: ", ++cas);
    if (!f()) puts("Fegla Won");
    else {
      printf("%d\n", g());
    }
  }
  return 0;
}
