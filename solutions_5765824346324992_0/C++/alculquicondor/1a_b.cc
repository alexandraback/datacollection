#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 1005

using namespace std;

typedef long long ll;
int M[MAXN], B, N;

ll how_many(ll t) {
  ll ans = 0;
  for (int i = 0; i < B; ++i)
    ans += (t + M[i] - 1) / M[i];
  return ans;
}

int solve() {
  cin >> B >> N;
  for (int i = 0; i < B; ++i)
    cin >> M[i];
  --N;
  ll lo = 0, hi = 100000LL * N, mid = 0;
  while (hi - lo > 1) {
    mid = (hi + lo) >> 1;
    if (how_many(mid) <= N)
      lo = mid;
    else
      hi = mid;
  }
  int id;
  ll cnt = how_many(lo);
  //cerr << lo << ' ' << cnt << endl;
  for (id = 0; id < B; ++id) {
    if (lo % M[id] == 0) {
      if (cnt == N)
        break;
      ++cnt;
    }
  }
  return id + 1;
}

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for (int cs = 1; cs <= tc; ++cs) {
    cout << "Case #" << cs << ": ";
    cout << solve();
    cout << endl;
  }
  return 0;
}
