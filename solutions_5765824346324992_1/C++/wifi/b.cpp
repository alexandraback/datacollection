#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;


int main() {
 int b, t, ans, mm;
 long long m[1010], x, y, n, k, nn;
  scanf("%d%",&t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d%lld", &b, &n);
    mm = 100100;
    for(int i = 0; i<b; i++) {
      scanf("%lld", m+i);
      if(mm > m[i])
        mm = m[i];
    }
    y = (long long)mm * n;
    x = 0;
    k = 0;
    while(x < y  && k != n) {
      long long z = (x + y)/2;
      k = b;
      for(int i = 0; i<b; i++) {
        k += z/(long long)m[i];
      }
      if(k >= n)
        y = z;
      else
        x = z + 1;
    }
    nn = b;    
    for(int i = 0; i<b; i++) {
      nn += y/(long long)m[i];
    }
    long long c = nn - n;
    ans = 0;
    k = (y / m[0]) * m[0];
    for(int i = 1; i<b; i++) {
      x = (y / m[i]) * m[i];
      if(k < x) {
        k = x;
        ans = i;
      }
    }
    for(int i = b-1; i>= 0; i--) {
      x = (y / m[i]) * m[i];
      if(k == x) {
        c--;
        if(c < 0) {
          ans = i;
          break;
        }
      }
    }
    printf("Case #%d: %d\n", tc, ans+1);
  }
  return 0;
}