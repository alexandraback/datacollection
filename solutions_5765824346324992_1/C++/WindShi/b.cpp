#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, a[1001], c[1001];

int calc(long long now){
     if (now < 0) return 0;
     long long cnt = 0;
     for (int i = 1; i <= n; i++) 
     {
          cnt += now / a[i] + 1;
          if (cnt > m) return m + 1;
     }
     return cnt;
}

int main(){
     freopen("b.in", "r", stdin);
     freopen("b.out", "w", stdout);
     scanf("%d", &test);
     for (int uu = 1; uu <= test; uu++)
     {
          printf("Case #%d: ", uu);
          scanf("%d%d", &n, &m);
          for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
          long long Left = -1, Right = 1LL << 60LL, Mid = (Left + Right) >> 1;
          for (; Left + 1 < Right; Mid = (Left + Right) >> 1)
               if (calc(Mid) < m) Left = Mid;
               else Right = Mid;
          int num = m - calc(Left), cnt = 0;
          for (int i = 1; i <= n; i++) 
               if (!(Right % a[i])) c[++cnt] = i;
          printf("%d\n", c[num]);
     }
}
