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

int main(){ IO;
  int t;
  cin >> t;

  rep(ncase,1,t+1){
    cout << "Case #" << ncase << ": ";

    int n;
    cin >> n;

    vi v(n);
    REP(i,n) cin >> v[i];

    lld x = 0;
    lld mx = 0;
    REP(i,n-1){
      if(v[i] > v[i+1]){
        lld diff = v[i] - v[i+1];
        x += diff;
        mx = max(mx, diff);
      }
    }

    lld y = 0;
    REP(i,n-1){
      y += min((lld)v[i], mx);
    }

    cout << x << " " << y << endl;
  }

  return 0;
}
