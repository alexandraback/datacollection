#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

char s[111][111];
char ch[111][111];
int cnt[111][111];
int sz[111];

int main() {
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));
  //std::ios::sync_with_stdio(0);
  //std::cin.tie(0);
  int tt;
  scanf("%d", &tt);
  for (int nc = 1; nc <= tt; ++nc) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s[i] + 1);
      sz[i] = 1;
      cnt[i][1] = 1;
      ch[i][1] = s[i][1];
      for (int j = 2; s[i][j]; ++j) {
        if (s[i][j] == ch[i][sz[i]]) ++cnt[i][sz[i]];
        else ++sz[i], ch[i][sz[i]] = s[i][j], cnt[i][sz[i]] = 1;
      }
    }
    int ans = -1;
    bool f = 1;
    for (int i = 2; i <= n && f; ++i)
      f = sz[i] == sz[1];
    if (f) {
      for (int i = 1; i <= sz[1] && f; ++i)
        for (int j = 2; j <= n && f; ++j)
          f = ch[j][i] == ch[1][i];
      if (f) {
        ans = 0;
        for (int i = 1; i <= sz[1]; ++i) {
          std::vector<int> v;
          for (int j = 1; j <= n; ++j)
            v.push_back(cnt[j][i]);
          std::sort(v.begin(), v.end());
          int vz = int(v.size());
          int x = v[vz >> 1];
          for (int j = 0; j < vz; ++j)
            ans += std::abs(x - v[j]);
        }
      }
    }
    if (ans == -1) {
      printf("Case #%d: Fegla Won\n", nc);
    } else {
      printf("Case #%d: %d\n", nc, ans);
    }
  }
}
