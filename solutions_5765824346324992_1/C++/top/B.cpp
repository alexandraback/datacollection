#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 1e3+10;

int b;
ll n,m[N];

inline bool check (ll k) {
  ll sum = 0;
  for (int i = 0;i < b;i ++) {
    sum += (k/m[i])+1;
    if (sum >= n) {
      return true;
    }
  }
  return false;
}

inline int solve () {
  scanf ("%d %lld", &b, &n);
  for (int i = 0;i < b;i ++) {
    scanf ("%lld", &m[i]);
  }

  if (n <= b) {
    return n;
  }

  ll lo = 1,hi = 1e15;
  while (lo < hi) {
    ll md = lo+hi >> 1;

    if (check (md)) {
      hi = md;
    } else {
      lo = md+1;
    }
  }

  ll sum = 0;
  for (int i = 0;i < b;i ++) {
    sum += (lo+m[i]-1)/m[i];
  }
  int k = n-sum;
  for (int i = 0;i < b;i ++) {
    if (lo%m[i] == 0 and (-- k) == 0) {
      return i+1;
    }
  }
  return -1;
}

int main () {
  int t;
  scanf ("%d", &t);

  for (int i = 1;i <= t;i ++) {
    printf ("Case #%d: %d\n", i, solve ());
  }
}
