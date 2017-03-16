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

#define NB 1024
int nc,nb,m[NB];
//  Time     Idx
map<int, set<int> > t;

int main() {
//  freopen("in.txt","r",stdin);
  freopen("B-small-attempt1.in","r",stdin);
  freopen("s-out.txt","w",stdout);

  int T;
  sf("%d",&T);
  rep(cas,1,T) {
    pf("Case #%d: ",cas);

    t.clear();
    sf("%d%d",&nb,&nc);
    rep(i,1,nb) sf("%d",m+i);

    int ans=0,
        cnt=0;
    rep(i,1,nb) {
      t[m[i]].insert(i);
      ++cnt;
//      pf("customer: %d - baber:%d  [ok at: %d]\n",cnt,i,m[i]);
      if (cnt==nc) {
        pf("%d\n",i);
        ans=i;
        break;
      }
    }
    if (ans) continue;

    int flag=0;
    while (1) {
      if (!flag && sz(t)==1) {
        nc=(nc-1)%cnt+1;
        cnt=0;
        flag=1;
      }
      int cur_time=t.begin()->x;
      set<int> &si=t.begin()->y;
      irep(i,si) {
        t[cur_time+m[*i]].insert(*i);
        ++cnt;
//        pf("customer: %d - baber:%d  [ok at: %d]\n",cnt,*i,cur_time+m[*i]);
        if (cnt==nc) {
          ans=*i;
          break;
        }
      }
      t.erase(t.begin());
//      if (cnt%1000000==0)
//      pf("|t|=%d cnt=%d\n",sz(t),cnt);
      if (ans) break;
    }
    pf("%d\n",ans);
  }
  return 0;
}
