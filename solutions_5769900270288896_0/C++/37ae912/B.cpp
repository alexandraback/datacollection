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

int R, C, n;

int get(int r, int c, int x){
  if(r<0 || c <0) return 0;
  if(r>=C || c>=R) return 0;

  int k = r*R + c;
  return (x>>k)&1;
}

int test(int x){
  int res = 0;
  for(int r=0;r<C;++r){
    for(int c=0;c<R;++c){
      if( get(r,c,x) && get(r+1,c,x) ) ++res;
      if( get(r,c,x) && get(r, c+1,x) ) ++ res;
    }
  }

  return res;
}


void solve(){
	// exact implementation appears here
  
  int ans = 1000;
  cin>>R>>C>>n;
  int K = 1<<(R*C);
  for(int i=0;i<K;++i){
    int j = i;
    int ct  = 0;
    while(j){
      if(j&1) ++ct;
      j>>=1;
    }

    if(ct == n){
      int res = test(i);
      if(res< ans) ans = res;
    }
  }

  cout<<ans<<endl;

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
