#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

bool A[50][50];
void scase() {
  int R, C, N;
  scanf("%d%d%d", &R, &C, &N);
  
  int result = 4 * N;
  REP(m, 2<<(R * C)) {
    int cnt = 0;
    int m2 = m;
    REP(i,R)REP(j,C) {
      bool b = m2 & 1;
      m2 >>= 1;
      A[i][j] = b;
      if (b) ++cnt;
    }
    if (cnt != N) continue;
    int tmp = 0;
    REP(i,R)REP(j,C) {
      if (i > 0 && A[i][j] && A[i-1][j]) ++tmp;
      if (j > 0 && A[i][j] && A[i][j-1]) ++tmp;
    }
    result = min(result, tmp);
  }
  
  printf("%d\n", result);
}

int main() {
  int Z;
  scanf("%d", &Z);
  REP(z,Z) {
    printf("Case #%d: ", z+1);
    scase();
  }
}    
