#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define rep(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define repd(i,a,b) for(int (i)=(b)-1;(i)>=(a);(i)--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair
#define countbits(x) __builtin_popcount(x)
#define countbitslld(x) __builtin_popcountll(x)

typedef long long int lld;
typedef vector<int> vi;
typedef vector<lld> vlld;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const lld maxt = 100000LL * 100000LL * 100000LL;

vi state(vi v, lld t){
  REP(i,v.size()){
    v[i] = t % v[i];
  }
  return v;
}

lld f(lld t, vi v){
  lld cnt = 0;
  REP(i,v.size()) cnt += t / v[i];
  return cnt + v.size();
}

int main(){ IO;
  int t;
  cin >> t;

  rep(ncase,1,t+1){
    cout << "Case #" << ncase << ": ";

    int b, n;
    cin >> b >> n;

    vi v(b);
    REP(i,b) cin >> v[i];

    lld low = -1, hi = maxt;
    while(hi - low > 1){
      lld mid = (low + hi) / 2;
      lld cnt = f(mid, v);
      if(n <= cnt){
	hi = mid;
      }else{
	low = mid;
      }
    }

    lld cnt = f(low, v);
    int ans = -1;
    vi final = state(v, low+1);

    REP(i,b){
      if(final[i] == 0){
	cnt++;
	if(cnt == n){
	  ans = i + 1;
	  break;
	}
      }
    }
    cout << ans << endl;
  }

  return 0;
}
