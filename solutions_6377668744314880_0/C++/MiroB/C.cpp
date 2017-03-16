#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<complex>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef long long int ll;
void solve() {
  int n;cin>>n;
  vector<complex<ll> > v;
  REP(i,n) {
    ll x,y;cin>>x>>y;
    v.push_back(complex<ll> (x,y));
  }
  vector<int> rval(n,n-1);
  REP(ss,1<<n) {
    int cnt=n;
    REP(i,n) if(ss & (1<<i)) cnt--;
    REP(i,n) if(ss & (1<<i)) {
      REP(j,n) if(i!=j)if(ss & (1<<j)) {
        int all_left=1;
        REP(z,n) if(ss &(1<<z)){
          complex<ll> a=v[z]-v[i];
          complex<ll> b=v[j]-v[i];
          if(imag(a*conj(b))<0) all_left=0;
        }
        if(all_left) {
          rval[i]=min(rval[i], cnt);
          rval[j]=min(rval[j],cnt);
        }
      }
    }
  }
  REP(i,n) {
    cout<<endl<<rval[i];
  }

}
int main() {
  int T;cin>>T;
  REP(i,T) {
    cout<<"Case #"<<(i+1)<<": ";
    solve();
    cout<<endl;
  }
}
