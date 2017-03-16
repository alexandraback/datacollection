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
typedef complex<ll> pt;
class srtr{
  public:
    bool operator()(const pt &a, const pt&b) {
      return imag(a*conj(b))<0;

    }
};
int rrr() {
  return rand()%2000000-1000000;
}
void solve() {
  int n;cin>>n;
  vector<complex<ll> > v;
  REP(i,n) {
    ll x,y;cin>>x>>y;
    v.push_back(complex<ll> (x,y));
  }
  vector<int> rval(n,n-1);
  REP(origin,n)  {
    while(1) {
      vector<pt> f;
      vector<pt> g;
      pt rpt(rrr(), rrr());
      int ok_split=1;
      REP(j,n) if(j!=origin) {
        pt p=v[j]-v[origin];
        ll dp=real(rpt*conj(p));
        if(dp==0) {
          ok_split=0;
        }
        if(dp<0)
          f.push_back(p);
        else g.push_back(p);
      }
      if(!ok_split) continue;
      sort(f.begin(), f.end(), srtr());
      sort(g.begin(), g.end(), srtr());
      f.erase(unique(f.begin(), f.end()),f.end());
      g.erase(unique(g.begin(), g.end()),g.end());
      int S=g.size();
      int T=f.size();
      int ptr=0;
      REP(i,f.size()) {
        while(ptr<S && imag(f[i]*conj(g[ptr]))<0) {
          ++ptr;
        }
        int eq=0;
        if(ptr<S && imag(f[i]*conj(g[ptr]))==0) eq=1;
        int l=i+S-ptr-eq,r=T-i-1+ptr;
        rval[origin]=min(rval[origin], min(r,l));
      }
      swap(f,g);
      swap(T,S);
      ptr=0;
      REP(i,f.size()) {
        while(ptr<S && imag(f[i]*conj(g[ptr]))<0) {
          ++ptr;
        }
        int eq=0;
        if(ptr<S && imag(f[i]*conj(g[ptr]))==0) eq=1;
        int l=i+S-ptr-eq,r=T-i-1+ptr;
        rval[origin]=min(rval[origin], min(r,l));
      }
    break;
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
