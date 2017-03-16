#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int B, N, M[1001];
ll served(ll t) {
  if (t < 0) return 0;
  ll n = 0;
  for (int i = 0; i < B; ++i) {
    n += 1 + t / M[i];
  }
  return n;
}
bool check(ll t) {
  return served(t) >= N;
}
int main() {
  int T; cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    cout << "Case #" << tc << ": ";
    cin >> B >> N;
    for (int i = 0; i < B; ++i)
      cin >> M[i];
    ll lo = 0, hi = 1LL<<40;
    while (lo < hi) {
      ll mid = (lo + hi)/2;
      if (check(mid))
        hi = mid;
      else
        lo = mid + 1;
    }
    //cout << served(0) << endl;
    //cout << served(1) << endl;
    ll t = lo;
    assert(served(t) >= N && served(t-1) < N);
    //cout << "t = " << t << endl;
    ll k = N - served(t - 1);
    //cout << "k = " << k << endl;
    vector<int> barbers;
    for (int i = 0; i < B; ++i) {
      if (t % M[i] == 0)
        barbers.push_back(i+1);
    }
    cout << barbers[k-1] << endl;
  }
}
