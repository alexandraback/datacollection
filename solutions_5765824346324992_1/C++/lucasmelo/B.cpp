#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef DEBUG
#include "/home/lucas/Topcoder/debug.h"
#define dbg(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#else
#define dbg(args...)
#endif

int b;
ll n;
#define MAXN 2000
ll m[MAXN];

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    cin >> b >> n;
    for(int i=0; i<b; i++) {
      cin >> m[i];
    }

    ll l = 0;
    ll u = 10000000000000000ll;
    while (l < u) {
      ll h = (l+u)>>1;

      ll qtd = 0;
      for(int i=0; i<b; i++) {
        qtd += h / m[i] + 1;
      }
      if (qtd >= n) u = h;
      else l = h+1;
    }
    ll qtd=0;
    if (l > 0) {
      for(int i=0; i<b; i++) {
        qtd += (l-1) / m[i] + 1;
      }
    }

    ll y = -1;
    for(int i=0; i<b; i++) {
      if (l%m[i] == 0) {
        qtd ++;
        if (qtd == n) {
          y = i+1;
          break;
        }
      }
    }

    printf("Case #%d: %lld\n", cn, y);
  }
  return 0;
}
