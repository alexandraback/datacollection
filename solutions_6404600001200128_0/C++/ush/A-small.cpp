#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

int vs[1010];

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    int n;
    scanf("%d", &n);
    REP(i, n){
      scanf("%d", &vs[i]);
    }
    
    int res1 = 0;
    int maxi = 0;
    for(int i = 1; i < n; ++i){
      if(vs[i-1] > vs[i]){
	res1 += vs[i-1] - vs[i];
	maxi = max(maxi, vs[i-1] - vs[i]);
      }
    }
    
    int res2 = 0;
    for(int i = 1; i < n; ++i){
      if(vs[i-1] < maxi){
	res2 += vs[i-1];
      }else{
	res2 += maxi;
      }
    }
        
    printf("Case #%d: %d %d\n", iCase+1, res1, res2);
  }
  return 0;
}
