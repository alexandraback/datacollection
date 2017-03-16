// Author: Xujie Si
// Email: six@gatech.edu
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i,X) for(int i=0;i<(X);++i)
#define PB(X) push_back( (X) )

typedef long long LL;
typedef vector<int> VI;

priority_queue<int> maxQ; // largest on the top
priority_queue<int, VI, greater<int> > minQ; // smallest on the top

auto cmp1 = [](int& a, int& b) -> bool {return a>b;};
auto dbg = ostream_iterator<int>(cerr, ",");

LL B,N;
LL bar[1<<20];

LL test(LL t)
{
  LL res = 0;
  for(int i=0;i<B;++i){
    res += (t + bar[i] -1) / bar[i]; 
    if(res >=N) return N;
  }

  return res;
}

void solve(){
  // exact implementation appears here

  cin>>B>>N;
  for(int i=0;i<B;++i)cin>>bar[i];

  // 10^12, 10^3*4
  LL l=0, r = 1LL<<62;
  while(l<r){
    LL mid = (l+r+1)/2;
    if(test(mid) < N) l = mid;
    else r = mid - 1;
  }

  //fprintf(stderr, "\nn=%lld\n",N);



  LL ct = N - test(l);

  //fprintf(stderr,"ct=%lld  l=%lld\n",ct,l);

  if(ct <= 0) fprintf(stderr,"ct is <= 0");

  int ans = -1;
  for(int i=0;i<B;++i){
    if( (l % bar[i]) ==0 ){
      --ct;
      if(ct == 0){
	ans = i+1;
	break;
      }
    }
  }

  if(ans == -1){
    fprintf(stderr, "ERROR ct=%lld l=%lld\n", ct, l);
  }
  else
    printf("%d\n", ans);

}

int main()
{
  int cs = 0, T;
  scanf("%d",&T);
  while(++cs <= T){
    printf("Case #%d: ", cs);
    solve();
  }
  return 0;
}
