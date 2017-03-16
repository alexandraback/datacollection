#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdint>
#include <cstdio>
using namespace std;

void solve()
{
  int b, n; cin>>b>>n;
  vector<int64_t> m(b);
  for (auto &i: m) cin>>i;

  int64_t lo = -1, hi = 10000000000000000;

  while (hi - lo > 1) {
    int64_t mi = (lo + hi)/2;

    int64_t tot = 0;
    for (auto &i: m) {
      tot += mi / i + 1;
    }

    if (tot >= n)
      hi = mi;
    else
      lo = mi;
  }

  // cerr << "*** " << lo <<", " << hi << endl;

  int64_t prev = 0;
  for (auto &i: m) {
    prev += max(0L, lo / i + 1);
  }
  // cout << prev << ", " << n << ", " << hi << endl;

  for (int i=0;i<b;i++) {
    if (hi%m[i] == 0) {
      prev++;
      if (prev==n) {
        cout << i+1 << endl;
        return;
      }
    }
  }
}

int main() {
  int t; cin>>t;
  for (int cn=1;cn<=t;cn++){
    cout << "Case #" << cn << ": ";

    solve();
    cout << flush;
  }
  return 0;
}
