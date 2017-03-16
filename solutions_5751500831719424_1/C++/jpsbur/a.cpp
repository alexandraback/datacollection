#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int maxN = 100;
const int maxL = 101;

int n;
char s[maxN][maxL];
char ss[maxL];
int l;
int st[maxN];
int a[maxN][maxL];

int main () {
  int nt;
  assert (scanf ("%d", &nt) == 1);
  for (int tt = 1; tt <= nt; ++tt) {
    printf ("Case #%d: ", tt);
    assert (scanf ("%d", &n) == 1);
    for (int i = 0; i < n; ++i) {
      assert (scanf ("%s", s[i]) == 1);
    }
    l = 0;
    for (int i = 0; s[0][i]; ++i) {
      if (i == 0 || s[0][i] != s[0][i - 1]) {
        ss[l++] = s[0][i];
      }
    }
    for (int i = 0; i < n; ++i) {
      st[i] = 0;
    }
    bool fail = false;
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j < n; ++j) {
        a[j][i] = 0;
        while (s[j][st[j]] == ss[i]) {
          ++st[j];
          ++a[j][i];
        }
        if (a[j][i] == 0) {
          fail = true;
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      if (s[j][st[j]]) {
        fail = true;
      }
    }
    if (fail) {
      printf ("Fegla Won\n");
      continue;
    }
    int sum = 0;
    for (int i = 0; i < l; ++i) {
      int best = (maxL + 1) * n;
      for (int x = 1; x <= maxL; ++x) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
          cur += abs (x - a[j][i]); 
        }
        if (cur < best) {
          best = cur;
        }
      }
      assert (best < (maxL + 1) * n);
      sum += best;
    }
    printf ("%d\n", sum);
  }
  return 0;
}
