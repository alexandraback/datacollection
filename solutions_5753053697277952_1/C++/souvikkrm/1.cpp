#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>

#define LL long long
#define vi vector<int>
#define pb push_back
#define sz size
#define all(x) (x).begin(),(x).end()
#define it iterator
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define REPX(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DEP(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define REX(i,x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end();i++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define st string
#define ffo find_first_of
#define su substr
#define vs vector<st>
#define vpii vector<pii >
#define ub upper_bound
#define lb lower_bound
#define mems(x) memset(x,0,sizeof(x))
#define memc(x,y) memcpy(x,y,sizeof(y))
#define pic pair<int,char>
#define cl clear
#define fr front
#define em empty
#define ord(c) (c-'A')
#define inv_ord(c) (c+'A')
#define rev reverse
#define MAX 26
using namespace std;
pic p[MAX];
inline int get_max(int n)
{
  int m=0;
  REP(i,0,n) m=max(m,p[i].fi);
  return m;
}
int main()
{
  int tc; cin>>tc;
  REP(t,0,tc)
  {
    int n,tot=0; cin>>n;
    REP(i,0,n)
    {
      cin>>p[i].fi;
      p[i].se=inv_ord(i);
      tot+=p[i].fi;
    }
    cout<<"Case #"<<t+1<<": ";
    while(tot)
    {
     sort(p,p+n); rev(p,p+n);
     char c=p[0].se;
     cout<<c;
     p[0].fi--; tot--;
     if(!tot) break;
     sort(p,p+n); rev(p,p+n);
     c=p[0].se;
     p[0].fi--; tot--;
     if(get_max(n)>(tot>>1)) { cout<<" "; p[0].fi++; tot++; } //undo
     else cout<<c<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
