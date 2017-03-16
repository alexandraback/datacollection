#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
// TIPS: {{{
// speed up iostream: ios_base::sync_with_stdio(0); cin.tie(0);
// memset(arr, 0, sizeof(arr))
// }}}
// {{{
template<typename A, typename B>
ostream& operator <<(ostream& s, const pair<A, B>& p)
{
  return s << "(" << p.first << "," << p.second << ")";
}
template<typename T>
ostream& operator <<(ostream& s, const vector<T>& c)
{
  s << "[ ";
  for (auto it : c) s << it << " ";
  s << "]";
  return s;
}
// }}}

typedef pair<char, int> party;

int main()
{
  int T;
  int n;
  party p[30];
  cin >> T;
  for (int TT = 1; TT <= T; ++TT) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      p[i].first = 'A' + i;
      cin >> p[i].second;
    }
    sort(p, p + n, [](party p1, party p2) { return p1.second > p2.second; });

    cout << "Case #" << TT << ": ";
    int diff = p[0].second - p[1].second;
    while (diff) {
      diff -= 1;
      cout << p[0].first;
      if (diff) {
        diff -= 1;
        cout << p[0].first;
      }
      cout << " ";
    }
    for (int i = 2; i < n; ++i) {
      int remain = p[i].second;
      while (remain) {
        remain -= 1;
        cout << p[i].first;
        if (remain) {
          remain -= 1;
          cout << p[i].first;
        }
        cout << " ";
      }
    }
    int remain = p[1].second;
    while (remain) {
      remain -= 1;
      cout << p[0].first << p[1].first << " ";
    }
    cout << endl;
  }
  return 0;
}

// vim: fdm=marker fdl=0

