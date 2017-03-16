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
int n, K;
ll ts[1010];

ll count(ll t) {
  ll res = 0;
  REP(i, n){
    res += t / vs[i] + 1;
  }
  return res;
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    scanf("%d%d", &n, &K);
    REP(i, n){
      scanf("%d", &vs[i]);
    }
    
//     REP(i, n)
//       ts[i] = 0;
//     int res1 = -1;
//     REP(i, K){
//       ll mini = ts[0];
//       int idx = 0;
//       REP(j, n){
// 	if(ts[j] < mini){
// 	  mini = ts[j];
// 	  idx = j;
// 	}
//       }
//       ts[idx] += vs[idx];
//       res1 = idx+1;
//     }
//     cerr << "time1 is " << ts[res1-1]-vs[res1-1] << endl;
    
    ll left = -1;
    ll right = 10000000000000000LL;
    while(right-left > 1){
      ll med = (left + right) / 2;
      ll ct = count(med);
      if(ct < K){
	left = med;
      }else{
	right = med;
      }
    }
    REP(i, n){
      K -= (right+vs[i]-1) / vs[i];
    }
//     cerr << ">>" << K << endl;
    assert(K <= n);
    int res = -1;
    REP(i, n){
      if(right % vs[i] == 0){
	if(--K == 0){
	  res = i+1;
	  break;
	}
      }
    }
//     cerr << "time2 is " << right << endl;
//     assert(res1 == res);

    printf("Case #%d: %d\n", iCase+1, res);
    fflush(stdout);
  }
  return 0;
}
