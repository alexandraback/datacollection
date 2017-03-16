#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long ll;

const int N = 1005;

int a[N];
int n, k;

int func(ll t) {
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += t / a[i] + 1;
  }
  return sum >= k;
}

int func2(ll t) {
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += t / a[i] + 1;
  }
  ll d = sum - k;
  int cnt = 0;
  for (int i = n-1; i >= 0; --i) {
    if (t % a[i] == 0) {
      if (d == 0) return i+1;
      --d;
    }
  }

  return n;
}

int solve() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll l = 0, r = 1LL<<60;
  while (r-l>1) {
    ll mid = (l+r) >> 1;
    if (func(mid)) r = mid;
    else l = mid;
  }
  if (func(l)) return func2(l);
  return func2(r);

}

int main() {
  //freopen("a.in", "r", stdin);
  int T; cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    cout << "Case #" << tt << ": " << solve() << endl;
  }
  return 0;
}