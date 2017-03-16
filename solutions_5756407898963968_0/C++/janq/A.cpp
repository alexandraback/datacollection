// pre-written code {{{
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
#include <iostream>
#include <cassert>
#include <set>
#define FOR(i,n) for(int _n=n,i=0;i<_n;++i)
#define FR(i,a,b) for(int _b=b,i=a;i<_b;++i)
#define CL(x) memset(x,0,sizeof(x))
#define PN printf("\n");
#define MP make_pair
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define FORSZ(i,v) FOR(i,v.size())
#define FORIT(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
///////////////////////////////////////////////////////////////////////////////////
// }}}

int a[4][4],b[4][4];

void solve(){
  int ra,rb;
  scanf("%d",&ra);
  FOR(i,4) FOR(j,4) scanf("%d",&a[i][j]);
  scanf("%d",&rb);
  FOR(i,4) FOR(j,4) scanf("%d",&b[i][j]);
  ra--; rb--;
  set<int> sa,sb;
  FOR(i,4) sa.insert(a[ra][i]);
  FOR(i,4) sb.insert(b[rb][i]);
  set<int> ret;
  FORIT(it,sa) if(sb.count(*it)) ret.insert(*it);
  if(ret.SZ == 0) {
    printf("Volunteer cheated!\n");
  } else if(ret.SZ >1) {
    printf("Bad magician!\n");
  } else {
    printf("%d\n",*ret.begin());
  }

}

int main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
