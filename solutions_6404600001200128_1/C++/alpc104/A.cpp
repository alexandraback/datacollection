#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <limits>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define x first
#define y second
#define sf scanf
#define pf printf
#define vec vector
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define clr(a,b) memset(a,b,sizeof(a))
#define bin_cnt(x) __builtin_popcount(x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define srep(sub,s) for(int sub=s&(s-1);sub;sub=(sub-1)&s)
#define irep(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define irrep(i,a) for(__typeof(a.rbegin()) i=a.rbegin();i!=a.rend();i++)
#define inf numeric_limits<int>::max()
#define finf numeric_limits<double>::infinity()
#define eps 1e-8
#pragma GCC optimize ("O3")
#define o3 __attribute__((optimize("O3")))
#pragma comment(linker, "/STACK:32505856")

template<class T> inline T sqr(T a) {return a*a;}
template<class T> inline void gmin(T&a,T b) {if(a>b)a=b;}
template<class T> inline void gmax(T&a,T b) {if(a<b)a=b;}
inline int dcmp(const double &a) {return a>eps?1:(a<-eps?-1:0);}
struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}}initializer;

#define N 1024
int n,a[N];

int main() {
//  freopen("in.txt","r",stdin);
  freopen("A-large.in","r",stdin);
  freopen("l-out.txt","w",stdout);

  int T;
  sf("%d",&T);
  rep(cas,1,T) {
    pf("Case #%d: ",cas);

    sf("%d",&n);
    rep(i,1,n) {
      sf("%d",a+i);
    }

    int ans1=0;
    rep(i,2,n) {
      if (a[i-1]>a[i]) {
        ans1+=a[i-1]-a[i];
      }
    }

    int rate=0;
    rep(i,2,n) {
      gmax(rate,a[i-1]-a[i]);
    }

    int ans2=0;
    rep(i,1,n-1) {
      ans2+=min(rate,a[i]);
    }
    pf("%d %d\n",ans1,ans2);
  }
  return 0;
}
