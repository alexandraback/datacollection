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

ll n, x;
vector<ll> v;


bool C(ll pos) {
  ll cnt = 0;
  rep(i, n) cnt += pos / v[i] + 1;
  return cnt >= x;
}

bool C2(ll pos) {
  ll cnt = 0;
  rep(i, n) cnt += pos / v[i] + 1;
  return cnt >= x-1;
}

int main() {
  int T;
  const ll inf = 10000000000000000LL;
  cin >> T;
  rep(t, T) {
    cout << "Case #" << t+1 << ": ";
    
    cin >> n >> x;
    v = vector<ll>(n);

    rep(i, n) cin >> v[i];

    ll lower = -1;
    ll upper = inf;
    while(upper - lower > 1) {
      ll mid = (lower + upper) / 2;
      //cout << mid << endl;
      if(C(mid)) upper = mid;
      else lower = mid;
    }
    upper--;
    ll cnt = 0;
    rep(i, n) cnt += upper / v[i] + 1;
    ll same = x - cnt;

    upper++;
    //cout << upper << endl;
    ll ans = -1;
    ll av = inf;
    rep(i, n) {
      ll val = v[i] - (upper%v[i]);
      if(upper%v[i] == 0) val = 0;
      if(av > val) 
	av = val;
    }
    //cout << same << endl;    
    rep(i, n) {
      ll val = v[i] - (upper%v[i]);
      if(upper%v[i] == 0) val = 0;
      //cout << i << " " << v[i] << " " << val << endl;
      if(av == val) {
	same--;
	if(same == 0) ans = i+1;
      }
    }
    
    if(ans == -1) cerr << "error!" << endl;
    cout << ans << endl;
  }
  
  return 0;
}
