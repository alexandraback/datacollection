// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int p[1010];
set<pair<int, int> > s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/A-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/A-small.txt", "w", stdout);
  int t, tt, i, n, total, x, y;
  set<pair<int, int> >::iterator it, it2;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    cin >> n;
    total = 0;
    s.clear();
    for (i = 0; i < n; i++) {
      cin >> p[i];
      s.insert({p[i], i});
      total += p[i];
    }
    while (!s.empty()) {
      if ((int)s.size() == 1) {
        it = s.begin();
        cout << char(it->second + 'A') << ' ';
        --total;
        x = it->first - 1;
        y = it->second;
        if (x > 0)
          s.insert({x, y});
        s.erase(it);
      } else {
        it = s.end();
        --it;
        it2 = it;
        --it2;
        if (2 * max(it2->first, it->first - 1) > (total - 1)) {
          x = it->first - 1;
          y = it->second;
          cout << char(it->second + 'A');
          if (x > 0)
            s.insert({x, y});
          x = it2->first - 1;
          y = it2->second;
          cout << char(it2->second + 'A') << ' ';
          if (x > 0)
            s.insert({x, y});
          s.erase(it);
          s.erase(it2);
          total -= 2;
        } else {
          x = it->first - 1;
          y = it->second;
          cout << char(it->second + 'A') << ' ';
          if (x > 0)
            s.insert({x, y});
          s.erase(it);
          total -= 1;
        }
      }
    }
    cout << '\n';
  }
  return 0;
}