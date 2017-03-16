#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rab(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define Fi(n) rep(i,n)
#define Fj(n) rep(j,n)
#define Fk(n) rep(k,n)
#define all(v) (v).begin(),(v).end()

int N;
int m[1000];

int eaten(int s) {
  int i;
  int t = 0, r = 0;

  Fi(N) {
    if (i == 0) {
      r = m[i];
    } else {
      if (m[i] < r) break;
      r = m[i];
    }

    if (i < N - 1) {
      r -= s;
      if(r < 0) {
        t += (s + r);
        r = 0;
      } else {
        t += s;
      }
      //printf("%d --> %d %d %d\n", j,i,t,r);
    }
  }

  if (i < N) return 1000000000;
  return t;
}


int main() {
  int T, cs;
  int i,j;
  int c1,c2;

  scanf("%d", &T);

  rab(cs,1,T) {
    scanf("%d",&N);

    Fi(N) scanf("%d",&m[i]);

    c1 = 0;

    Fi(N) {
      if(i > 0 && m[i] < m[i-1]) c1 += (m[i-1] - m[i]);
    }

    int lo,hi,mid;

    lo = 0;
    hi = 100000000;
    int m,c;

    while(lo <= hi) {
      m = (lo + hi) / 2;
      //printf("%d %d\n",lo,hi);

      if (eaten(m) < 10000000) {
        hi = m - 1;
      } else {
        lo = m + 1;
      }
    }

    while(true) {
      //printf("lo = %d\n",lo);
      if (eaten(lo) < 100000000) break;
      lo++;
    }

    c2 = eaten(lo);

    printf("Case #%d: %d %d\n", cs, c1, c2);
  }

  return 0;
}
