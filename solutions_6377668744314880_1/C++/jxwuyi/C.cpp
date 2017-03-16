#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long
const int maxn = 3000 + 10;
#include<complex>
#define CPX complex<LL>
#include<cmath>

const double eps = 1e-9;
const double pi = acos(-1);
inline int dcmp(const double&a){return fabs(a)<=eps?0:(a<0?-1:1);}

LL operator ^ (CPX a, CPX b) {return a.real() * b.imag() - a.imag() * b.real();}

struct Point {
  double rot;
  CPX p;
}tp;

bool cmp(const Point&a, const Point&b){return a.rot < b.rot;}

CPX P[maxn],Q[maxn];
int N,M;

int solve() {
  
  if(N <= 2) return 0;
  
  vector<Point> dat;
  for(int i=0;i<N;++i) {
    tp.rot=atan2(P[i].imag(), P[i].real());
    tp.p = P[i];
    dat.push_back(tp);
    tp.rot += 2 * pi;
    dat.push_back(tp);
  }
  
  sort(dat.begin(), dat.end(), cmp);
  int ans=N;
  int ptr = 0;
  for(int i=N;i<dat.size();++i) {
    double cur = dat[i].rot;
    while(dat[ptr].rot+pi+eps <= cur
          || 
          ((dcmp(dat[ptr].rot+pi-cur)==0)&&
           (dat[ptr].p^dat[i].p)<=0)) ++ ptr;
    ans=min(ans,i-ptr);
  }
  return ans;
}

void run() {
  scanf("%d", &M);
  int x,y;
  for(int i=0;i<M;++i){
    scanf("%d %d",&x,&y);
    Q[i]=CPX(x,y);
  }
  for(int c=0;c<M;++c){
    N=0;
    for(int i=0;i<M;++i)
      if(i!=c) P[N++]=Q[i]-Q[c];
    printf("%d\n", solve());
  }
}

int main() {
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  
  int test;
  scanf("%d", &test);
  for(int no=1;no<=test;++no) {
    printf("Case #%d:\n",no);
    run();
  }
}
