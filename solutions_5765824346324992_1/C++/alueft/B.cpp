#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll m[1000];
ll b, n;

ll f(ll t) {
  if (t < 0)
    return 0;
  ll r = 0;
  for (int i = 0; i < b; i++)
    r += (t+m[i]-1LL)/m[i];
  return r;
}

int main() {
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    cout << "Case #" << T << ": ";
    cin >> b >> n;
    for (int i = 0; i < b; i++)
      cin >> m[i];
    ll lo = -1, hi = 314159265358979323LL;
    while (lo+1 < hi) {
      ll mid = (lo+hi)/2LL;
      ll fmid = f(mid);
      if (fmid >= n)
        hi = mid;
      else
        lo = mid;
    }
    //cout << "at " << lo << " " << hi << " f " << f(lo) << " " << f(hi) << endl;
    vector<int> ab;
    for (int i = 0; i < b; i++)
      if (lo % m[i] == 0)
        ab.push_back(i+1);
    cout << ab[n-f(lo)-1] << "\n";
  }
  return 0;
}
