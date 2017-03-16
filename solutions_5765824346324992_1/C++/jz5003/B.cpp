//my magic will tear you apart!
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

const int N = 1010;
int t, b, m[N];
ll n;
ll val(ll ti) {
  if(ti < 0) return 0;
  ll tot = 0; 
  for(int j = 0; j < b; j++) {
    tot += ti/m[j] + 1;
  }
  return tot;
}
bool check(ll ti) {
  ll v = val(ti);
  return v >= n;
}
//minimum time such that >=n people are taking haircut
ll bsearch(ll lo, ll hi) {
  ll mid = (lo + hi)/2;
  if(lo >= hi) {
    if(check(hi)) return hi;
    return lo;
  }
  if(check(mid)) {
    return bsearch (lo, mid);
  }
  return bsearch(mid + 1, hi);
}
int main() {
  if(fopen("B.in","r")) freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  cin >> t;
  for(int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    cin >> b >> n;
    for(int j = 0; j < b; j++) {
      cin >> m[j];
    }
    ll ans = bsearch(0,100000000000000L);
    ll cur = val(ans - 1);
    int ret = -1;
    for(int j = 0; j < b; j++) {
      if(ans % m[j] == 0)
         cur++;
      if(cur == n) {
        ret = j;
        break;
      }
    }
    cout << ret + 1 << endl;
  }
  return 0;
}