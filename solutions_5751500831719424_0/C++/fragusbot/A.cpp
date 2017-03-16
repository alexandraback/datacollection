#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;

int n;
int pos[105];
int cnt[105];
string s[105];

int main() {
  freopen("in", "r", stdin); freopen("out", "w", stdout); freopen("log", "w", stderr);
  int tt; scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector<char> u;
    bool can = true;
    for (int i = 0; i < n; ++i) {
      vector<char> cur;
      for (int j = 0; j < s[i].length(); ++j)
        if (cur.empty() or s[i][j] != cur.back()) cur.push_back(s[i][j]);
      if (u.empty()) u = cur; else
      if (u != cur) can = false;
    }
    for (int i = 0; i < n; ++i) pos[i] = s[i].length() - 1;
    printf("Case #%d: ", cc);
    if (!can) puts("Fegla Won"); else {
      int ans = 0;
      for (int k = (int)u.size() - 1; k >= 0; --k) {
        char c = u[k];
        for (int i = 0; i < n; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) {
          while (pos[i] >= 0 and s[i][pos[i]] == c) {
            --pos[i]; ++cnt[i];
          }
        }
        int add = 1e9;
        for (int i = 0; i < n; ++i) {
          int cur = 0;
          for (int j = 0; j < n; ++j) cur += abs(cnt[i] - cnt[j]);
          add = min(add, cur);
        }
        ans += add;
      }
      printf("%d\n", ans);
    }

  }
  return 0;
}