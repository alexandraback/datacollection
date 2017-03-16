#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void Solve() {
  int N;
  cin >> N;

  set<pair<int, char>> S;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;

    S.insert({a, 'A' + i});
  }

  while (true) {
    assert(S.size() >= 2);
    auto it = S.end();
    --it;
    auto pit = it;
    --pit;

    if (it->first != pit->first) {
      auto p = *it;
      cout << p.second << ' ';
      S.erase(p);
      if (p.first > 1) {
        S.insert({p.first - 1, p.second});
      }
    } else {
      for (auto i = S.begin(); i != pit; ) {
        for (int c = 0; c < i->first; ++c) {
          cout << i->second << ' ';
        }
        i = S.erase(i);
      }

      char one = pit->second;
      char two = it->second;
      assert(pit->first == it->first);
      for (int i = 0; i < it->first; ++i) {
        cout << one << two << ' ';
      }
      break;
    }
  }

  cout << endl;
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/A-small-attempt0.in", "rb", stdin);
  freopen("../Console/A-small-attempt0.out", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 0; tc < T; ++tc) {
    cout << "Case #" << tc + 1 << ": ";
    Solve();
  }

  return 0;
}
