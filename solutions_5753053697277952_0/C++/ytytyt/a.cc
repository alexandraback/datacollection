#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long LL;

int T, ti, n;

int solve() {
  cin >> n;
  int s = 0;
  vector<pair<int, char> > cnt;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    s += k;
    cnt.push_back(make_pair(k, i+'A'));
  }
  sort(cnt.begin(), cnt.end());
  int i = n-1;
  printf("Case #%d:", ti);
  while (s) {
    if (n == 2 && cnt[0].first == cnt[1].first) {
      s -= 2;
      cout << ' ' << cnt[0].second << cnt[1].second;
      cnt[0].first--;
      cnt[1].first--;
      continue;
    }
    s--;
    if (s != 0)
      cout << ' ';
    cout << cnt[i].second;
    cnt[i].first -= 1;
    if (i > 0 && cnt[i].first+1 == cnt[i-1].first) {
      i = i-1;
      continue;
    }
    i = n-1;
  }
  cout << endl;
  return 0;
}

int main() {
  cin >> T;
  for (ti = 1; ti <= T; ti++) {
    solve();
  }
  return 0;
}
