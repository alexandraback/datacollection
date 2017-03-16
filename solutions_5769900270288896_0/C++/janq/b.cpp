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
#include <sys/resource.h>
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
void stackSizeUnlimited() { struct rlimit rl; getrlimit(RLIMIT_STACK, &rl); rl.rlim_cur = RLIM_INFINITY; setrlimit(RLIMIT_STACK, &rl); }
///////////////////////////////////////////////////////////////////////////////////
// }}}

int dx[]={+1,-1,0,0};
int dy[]={0,0,+1,-1};
int X,Y,C;
int a[20][20];

bool dnu(int x, int y){
  return ((0<=x && x<X) && (0<=y && y<Y));
}

int deg(int x, int y){ 
  int ret=0;
  FOR(i,4) {
    if(dnu(x+dx[i],y+dy[i]) && a[x+dx[i]][y+dy[i]]==1) {
      ret++;
    }
  }
  return ret;
}

bool zlepsi(){
  FOR(x,X) FOR(y,Y) if(a[x][y]==1) {
    FOR(i,4) {
      int xx=x+dx[i];
      int yy=y+dy[i];
      if(!dnu(xx,yy)) continue;
      if(a[xx][yy]==1) continue;
      if(deg(xx,yy)-1<deg(x,y)) {
        a[x][y]=0;
        a[xx][yy]=1;
        return true;
      }
    }
  }
  return false;
}

void solve(){
  scanf("%d %d %d",&X,&Y,&C);
  int z = C;
  CL(a);
  FOR(x,X) FOR(y,Y) {
    if((x+y)%2==0) {
      a[x][y]=1;
      z--;
    }
  }
  if(z<=0) { printf("0\n"); return; }
  FOR(x,X) FOR(y,Y) if(a[x][y]==0) if(z>0) {
    if((x==0 || x==X-1) && (y==0 || y==Y-1)) {
      a[x][y]=1;
      z--;
    } 
  }
  FOR(x,X) FOR(y,Y) if(a[x][y]==0) if(z>0) {
    if(x==0 || y==0 || x==X-1 || y==Y-1) {
      a[x][y]=1;
      z--;
    }
  }
  FOR(x,X) FOR(y,Y) if(a[x][y]==0) if(z>0) {
      a[x][y]=1;
      z--;
  }
  while(zlepsi());
//  FOR(x,X) { FOR(y,Y) printf("%d",a[x][y]); PN; }
  int ret=0;
  FOR(x,X) FOR(y,Y) if(a[x][y]) ret+=deg(x,y);
  printf("%d\n",ret/2);
}

int main(){
  stackSizeUnlimited();
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
