#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef DEBUG
#include "/home/lucas/Topcoder/debug.h"
#define dbg(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#else
#define dbg(args...)
#endif

int n;

#define MAXN 100004
ll m[MAXN];

bool cando(ll x, ll &res) {
  res = 0;
  for(int i=0; i<n-1; i++) {
    if (m[i] - x <= m[i+1]) {
      res += m[i] - max(0ll, m[i]-x);
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    cin >> n;
    for(int i=0; i<n; i++) {
      cin >> m[i];
    }

    ll y = 0;
    for(int i=0; i<n-1; i++) {
      if (m[i] > m[i+1]) {
        y += m[i] - m[i+1];
      }
    }

    ll z = 0;
    ll l = 0;
    ll u = 100000;

    while (l < u) {
      ll aux;
      ll h = (l+u)>>1;
      if (cando(h, aux)) u = h;
      else l = h+1;
    }
    cando(l, z);

    printf("Case #%d: %lld %lld\n", cn, y, z);
  }
  return 0;
}
