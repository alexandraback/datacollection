#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("A-large.in", "rt", stdin);
  freopen("A-large.out", "wt", stdout);
  int t; cin >> t;
  for(int tst = 1; tst <= t; ++tst) {
    int n; cin >> n;
    vector<vector<int> > all(n);
    set<string> seq;
    for(int k = 0; k < n; ++k) {
      string s; cin >> s;
      string sq = "";
      for(int i = 0; i < (int)s.size(); ++i) {
        int j = i;
        while(j < (int)s.size() && s[j] == s[i]) ++j;
        sq += s[i];
        all[k].push_back(j - i);
        i = j - 1;
      }
      seq.insert(sq);
    }
    printf("Case #%d: ", tst);
    if(seq.size() > 1) puts("Fegla Won");
    else {
      int ans = 0;
      for(int j = 0; j < (int)all[0].size(); ++j) {
        int tot = 1 << 30;
        for(int i = 0; i < (int)all.size(); ++i) {
          int sum = 0;
          for(int k = 0; k < (int)all.size(); ++k) {
            sum += abs(all[i][j] - all[k][j]);
          }
          tot = min(tot, sum);
        }
        ans += tot;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
