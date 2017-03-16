#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
     int x, y, position;
     void Swap(node &A){
          swap(x, A.x);
          swap(y, A.y);
          swap(position, A.position);
     }
     node operator - (node &A){
          node res;
          res.x = x - A.x; res.y = y - A.y;
          res.position = position;
          return res;
     }
     long long dist() const{
          return 1LL * x* x + 1LL * y * y;
     }
} a[3011], A[3011];
int test, n, len;
node c[3011];
bool b[3011];
node angel[6011], Std;
const double eps = 1e-10;

long long xj(const node x, const node y){
   //  printf("%d %d %d %d\n", x.x, x.y, y.x, y.y);
     return 1LL * x.x * y.y - 1LL * x.y * y.x;
}

bool cmp(const node &x, const node &y){
     return x.x < y.x || (x.x == y.x && x.y < y.y);
}
bool cmp1(const node &x, const node &y){
     return atan2(x.y - Std.y, x.x - Std.x) < atan2(y.y - Std.y, y.x - Std.x);
}

int main(){
     freopen("c.in", "r", stdin);
     freopen("c.out", "w", stdout);
     scanf("%d", &test);
     for (int uu = 1; uu <= test; uu++)
     {
          printf("Case #%d:\n", uu);
          scanf("%d", &n);
          for (int i = 1; i <= n; i++)
               scanf("%d%d", &a[i].x, &a[i].y),
               a[i].position = i;
          int position = 1;
          for (int i = 2; i <= n; i++) 
               if (a[i].x < a[position].x || (a[i].x == a[position].x && a[i].y < a[position].y))
                    position = i;
          int x = a[position].x, y = a[position].y;
          for (int i = 1; i <= n; i++) a[i].x -= x, a[i].y -= y, A[i] = a[i];
          sort(a + 1, a + n + 1, cmp);
          len = 2;
          c[1] = a[1]; c[2] = a[2];
          for (int i = 3; i <= n; i++)
          {
               for (; len >= 2 && xj(a[i] - c[len - 1], c[len] - c[len - 1]) > 0; --len);
               c[++len] = a[i]; 
          }
          int len1 = len;
          for (int i = n - 1; i >= 1; i--)
          {
               for (; len >= len1 + 1 && xj(a[i] - c[len - 1], c[len] - c[len - 1]) > 0; --len);
               c[++len] = a[i]; 
          }
          --len;
          memset(b, false, sizeof(b));
          for (int i = 1; i <= len; i++) b[c[i].position] = true;
          //for (int i = 1; i <= cnt; i++) printf("%d %d\n", angel[i].x, angel[i].y);
          for (int i = 1; i <= n; i++)
               if (b[i]) printf("0\n");
               else
               {
                    int len = 0;
                    for (int j = 1; j <= n; j++) 
                         if (a[j].x != A[i].x || a[j].y != A[i].y) angel[++len] = a[j];
                    int cnt = len;
                    Std = A[i];
                    sort(angel + 1, angel + len + 1, cmp1);
                    for (int j = 1; j <= len; j++) angel[++cnt] = angel[j];
                    int ans = 1 << 30, Left = 1;
                    for (int j = 1; j <= len; j++)
                         {
                              Left = max(Left, j + 1);
                              for (; Left <= cnt && xj(A[i] - angel[j], A[i] - angel[Left]) > 0; ++Left);
                              ans = min(ans, Left - j - 1);
                            //  printf("cao %d %d %lld\n", j, Left, xj(A[i] - angel[j], A[i] - angel[Left]));
                         }
                    printf("%d\n", ans);
               }  
     }
}
     
