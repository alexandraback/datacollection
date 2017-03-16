#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i, a, b) for(int i = (a); i < (int)(b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i--)
#define repit(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define reprit(i, v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    cout << "Case #" << t+1 << ": ";
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    ll ans1 = 0;
    ll maxd = 0;
    rep(i, n-1) {
      if(v[i+1]-v[i] < 0) ans1 += v[i]-v[i+1];
      maxd = max(maxd, v[i] - v[i+1]);
    }
    
    ll ans2 = 0;
    rep(i, n-1) {
      ans2 += min(v[i], maxd);
    }
    
    cout << ans1 << " " << ans2 << endl;
  }
  
  return 0;
}
