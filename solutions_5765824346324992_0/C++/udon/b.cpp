#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF = 5000000000;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<int(m);++(i))
#define rep(i,n) reps(i,0,n)
ll T;

ll lcm(ll a, ll b){
  return a/__gcd(a,b)*b;
}

int main(){
  cin >> T;
  reps(times, 1, T+1) {
    ll ans = 0;
    ll b, n;
    vector<int> vec;
    ll lc = 1;
    cin >> b >> n;
    rep(i,b){
      ll t;
      cin >> t;
      vec.PB(t);
      lc = lcm(lc, t);
    }
    ll x = 0;
    rep(i, b){
      x += lc/vec[i];
    }
    int sec = 0;
    ll cnt = 0;
    priority_queue<P,vector<P>, greater<P> > pq;
    rep(i, b){
      pq.push(make_pair(0, i));
    }
    int lim = ((n-1+x) % x)+1;
    int idx;

    while(cnt <= lim) {
      P hd = pq.top();
      pq.pop();
      idx = hd.second;
      sec = hd.first;
      pq.push(make_pair(sec+vec[idx], idx));
      cnt++;
      if(lim==cnt)break;
    }


    printf("Case #%d: %d\n", times, idx+1);
  }

}
