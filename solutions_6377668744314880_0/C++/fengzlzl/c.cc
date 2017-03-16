#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point
{
    long long x;
    long long y;
friend bool operator < (const Point &n, const Point &m);

};

Point a[20];
long long q[20];

long long n, m;
long long ans[20];
Point squ[20];

long long cross(long long j, long long k, long long l)//求向量(k-j)叉积（l-k),<0即k在向量(l-j)的左手系
{
    long long x1 = a[k].x - a[j].x;
    long long y1 = a[k].y - a[j].y;
    long long x2 = a[l].x - a[k].x;
    long long y2 = a[l].y - a[k].y;
    return (x1*y2-x2*y1);
}

bool operator < (const Point &n, const Point &m)
{
   long long nx = n.x-a[0].x;
   long long ny = n.y-a[0].y;
   long long mx = m.x-a[0].x;
   long long my = m.y-a[0].y;
   long long cross = nx*my-ny*mx;
   return (cross>0 || cross == 0 && mx*mx+my*my > nx*nx+ny*ny);
}

bool Contain(long long x0, long long y0, long long x1, long long y1, long long x2, long long y2) {
    long long nx = x2 - x0;
    long long ny = y2 - y0;
    long long mx = x2 - x1;
    long long my = y2 - y1;
    if (nx * my - ny * mx != 0) return false;
    return min(x0, x1) <= x2 && x2 <= max(x0, x1) && min(y0, y1) <= y2 && y2 <= max(y0, y1);
}

void Solve(long long cut) {
    long long base = 0;
    for (long long i=0; i<m; i++)
      {
          if (a[i].y < a[base].y ||
              a[i].y == a[base].y && a[i].x < a[base].x)
            base = i;//找最低且最左边的点为基准点
      }
      swap(a[0], a[base]);
      if (m > 1) sort(a+1, a+m);//以基准点安叉积排序

      a[m] = a[0];
      q[0] = 0; q[1] = 1;
      long long top = 1;

            for (int i = 0; i < m; i++) {
        //cout << a[i].x << "," << a[i].y << endl;
      }

      for(long long i=2; i<=m; i++)//用栈求凸包
      {
         q[++top] = i;
         while (top >1 && cross(q[top-2],q[top-1],q[top]) <= 0)
         {
            q[top-1] = q[top];
            q[top] = 0;
            top--;
         }
      }


      for (long long i=0; i<top; i++) {
        for (long long j = 0; j < n; j++)
            if (Contain(a[q[i]].x, a[q[i]].y , a[q[i + 1]].x, a[q[i + 1]].y, squ[j].x, squ[j].y)) {
                if (cut < ans[j]) ans[j] = cut;
      }

      }
}

int main() {
    long long T;
    scanf("%I64d", &T);
    for (long long cas = 1; cas <= T; cas++) {
        scanf("%I64d", &n);
        for (long long i = 0; i < n; i++) {
                cin >> squ[i].x >> squ[i].y;

            ans[i] = n - 1;
        }
        if (n <= 3) {
            printf("Case #%I64d:\n", cas);
        for (long long i = 0; i < n; i++)
            printf("%I64d\n", 0LL);
            continue;
        }
        for (long long state = 1; state < (1LL << n); state++) {
            m = 0;
            for (long long i = 0; i < n; i++)
                if ((state >> i) & 1) {
                    a[m].x = squ[i].x;
                    a[m].y = squ[i].y;
                    m++;
                }

            Solve(n - m);
        }
        printf("Case #%I64d:\n", cas);
        for (long long i = 0; i < n; i++)
            printf("%I64d\n", ans[i]);
    }
    return 0;
}
