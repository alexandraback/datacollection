#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("A-small-attempt0.in", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  int t; scanf("%d", &t);
  for(int tst = 1; tst <= t; ++tst) {
    set<int> a[2];
    for(int k = 0; k < 2; ++k) {
      int r; scanf("%d", &r); --r;
      for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
          int c; scanf("%d", &c);
          if(i == r) a[k].insert(c);
        }
      }
    }
    vector<int> ans;
    for(int i : a[0])
      if(a[1].count(i))
        ans.push_back(i);
    printf("Case #%d: ", tst);
    if(ans.size() == 0) puts("Volunteer cheated!");
    else if(ans.size() == 1) printf("%d\n", ans[0]);
    else puts("Bad magician!");
  }
  return 0;
}
