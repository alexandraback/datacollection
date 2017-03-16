#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1001], test;

int main(){
     freopen("a.in", "r", stdin);
     freopen("a.out", "w", stdout);
     scanf("%d", &test);
     for (int uu = 1; uu <= test; uu++)
     {
          printf("Case #%d: ", uu);
          scanf("%d", &n);
          for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
          int ans = 0, Max = 0;
          for (int i = 2; i <= n; i++)
               if (a[i] < a[i - 1]) 
               {
                    ans += a[i - 1] - a[i];
                    Max = max(Max, a[i - 1] - a[i]);
               }
          printf("%d ", ans);
          ans = 0;
          for (int i = 1; i < n; i++)
               ans += min(Max, a[i]);
          printf("%d\n", ans);
     }
}
