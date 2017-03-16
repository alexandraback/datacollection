#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

class range {private: struct I{int x;int operator*(){return x;}bool operator!=(I& lhs){return x<lhs.x;}void operator++(){++x;}};I i,n;
public:range(int n):i({0}),n({n}){}range(int i,int n):i({i}),n({n}){}I& begin(){return i;}I& end(){return n;}};

void solve();

int main() {
  int T; cin >> T;
  for (int test : range(1, T+1)) {
    cout << "Case #" << test << ": ";
    solve();
  }
}

//=====

void solve() {
  int N, M; cin >> N >> M;
  vector<ll> L(N);
  for (int i : range(N)) cin >> L[i];

  // {
  //   ll t = 4, k = 0;
  //   ll tot = 0;
  //   for (int i : range(N)) {
  //     int s = (i <= k) ? t : (t - 1);
  //     if (s < 0) continue;
  //     tot += 1 + s / L[i];
  //   }
  //   cout<<tot<<endl;
  // }

  ll lo = -1, hi = 1LL << 50;
  while (hi - lo > 1) {
    ll mid = (hi + lo) / 2;
    ll t = mid / N, k = mid % N;

    ll tot = 0;
    for (int i : range(N)) {
      ll s = (i <= k) ? t : (t - 1);
      if (s < 0) continue;
      tot += 1 + s / L[i];
    }
    if (tot >= M) hi = mid;
    else lo = mid;
  }

  // cout << "#" << (hi / N) << " " << (hi % N) << endl;
  cout << (hi % N + 1) << endl;
}
