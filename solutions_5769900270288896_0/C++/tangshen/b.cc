#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
inline int bit(int n, int x){
  return (n >> x)&0x1;
}
inline int cntbit(int n){
  int ans = 0;
  while(n){
    ans += n&0x1;
    n >>= 1;
  }
  return ans;
}
int main(){
  int T;cin >> T;int idx = 0;
  while(T--){++idx;
    int R,C,N;cin >> R >> C >> N;
    int n = R*C; int maxn = 1<<(R*C);
    int ans = 1000000;
    for(int i=0;i<maxn;++i){
      if(cntbit(i)!=N)continue;
      int tans = 0;
      for(int j=0;j<n;++j){
        if(bit(i,j)==0)continue;
        if(j%C+1 < C && bit(i,j+1)!=0)
          ++tans;
        if(j/C+1 < R && bit(i,j+C)!=0)
          ++tans;
      }
      ans = min(ans,tans);
    }
    cout << "Case #" << idx << ": " << ans << endl;
  }
  return 0;
}
