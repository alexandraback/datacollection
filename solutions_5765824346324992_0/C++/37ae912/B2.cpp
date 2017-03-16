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
  }

  return res;
}

LL gcd(LL a , LL b){ return b==0 ? a : gcd(b,a%b);}

void solve(){
  // exact implementation appears here

  cin>>B>>N;
  for(int i=0;i<B;++i)cin>>bar[i];

  LL g = 1;
  for(int i=0;i<B;++i){
    g = g * bar[i] / gcd(g, bar[i]);
  }
  
  LL m = 0;
  for(int i=0;i<B;++i){
    m += g / bar[i];
  }

  N %= m;
  if(N==0) N = m;

  //fprintf(stderr, "N=%lld\n",N);
  int ans = 0;
  int t=0;
  while(true){
    for(int i=0;i<B;++i){
      if(t % bar[i] == 0){
	--N;
	if(N==0){
	  printf("%d\n",i+1);
	  return;
	}
      }
    }
    ++t;
  }
 

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
