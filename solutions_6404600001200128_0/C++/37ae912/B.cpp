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

bool test(LL t)
{
  LL res = 0;
  for(int i=0;i<B;++i){
    res += (t + bar[i] -1) / bar[i]; 
  }

  return res < N;
}

void solve(){
  // exact implementation appears here

  cin>>B>>N;
  for(int i=0;i<B;++i)cin>>bar[i];

  LL l=0, r = 1LL<<62;
  while(l<r){
    LL mid = (l+r+1)/2;
    if(test(mid)) l = mid;
    else r = mid - 1;
  }

  //fprintf(stderr, "\nn=%lld\n",N);

  LL ct = 0;
  for(int i=0;i<B;++i){
    ct += (l+bar[i]-1) / bar[i];
  }

  /*fprintf(stderr, "ct1=%lld l=%lld\n", ct, l);

 LL ct2 = 0;
 LL l2 = l+1;
 for(int i=0;i<B;++i){
   ct2 += (l2 + bar[i]-1) / bar[i];
 }
 fprintf(stderr, "ct2=%lld l2=%lld\n", ct2, l2);
  */


  ct = N - ct;


  int ans = -1;
  for(int i=0;i<B;++i){
    if( (l % bar[i]) ==0 ){
      --ct;
    }
    if(ct == 0){
      ans = i+1;
      break;
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
