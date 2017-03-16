#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 5000000000;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<int(m);++(i))
#define rep(i,n) reps(i,0,n)
ll T;

int main(){
  cin >> T;
  reps(times, 1, T+1) {
    ll ans1 = 0;
    ll ans2 = 0;
    ll n;
    cin >> n;
    vector<ll> vec;
    rep(i,n){
      ll t;
      cin>>t;
      vec.PB(t);
    }
    ll mx = 0;
    // 1
    rep(i, n-1){
      if(vec[i]>vec[i+1]) {
        mx = max(mx, vec[i]-vec[i+1]);
        ans1 += vec[i] - vec[i+1];
      }
    }
    //2
    rep(i, n-1){
      ans2 += min(mx, vec[i]);
    }

    printf("Case #%d: %lld %lld\n", times, ans1, ans2);
  }

}
