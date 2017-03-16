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

int main() {
  int T, cs;
  int N;
  int m[1000];
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

    for(j = 0; j <= 1000; j++) {
      int r = 0;
      int t = 0;

      Fi(N) {
        if (i == 0) {
          r = m[i];
        } else {
          if (m[i] < r) break;
          r = m[i];
        }

        if (i < N - 1) {
          r -= j;
          if(r < 0) {
            t += (j + r);
            r = 0;
          } else {
            t += j;
          }
          //printf("%d --> %d %d %d\n", j,i,t,r);
        }
      }
      if(i >= N) {
        c2 = t;
        break;
      }
      //printf("%d: %d\n", j,i);
    }

    printf("Case #%d: %d %d\n", cs, c1, c2);
  }

  return 0;
}
