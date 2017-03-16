#include <iostream>
#include <cstdio>
#include <cstring>

int r, c, n;

int solve()
{
   if (r > c)
   {
      int tmp = c;c = r;r = tmp;
   }
   if (r == 1)
   {
      if (n == c) return c - 1;
      else if (n <= c - (c >> 1)) return 0;
      else return ((n - (c - (c >> 1))) << 1) - (1 - (c & 1));
   }
   int a1, a2, a3, b1, b2, b3;
   if ((r*c) & 1)
   {
      b1 = ((r * c) >> 1) + 1;
      b2 = 0;
      b3 = (r & (~0 ^ 1)) + (c & (~0 ^ 1));
      a2 = ((r + c - 2) << 1) - b3 - 4;
      a3 = 4;
      a1 = b1 - a2 - a3;
   }
   else
   {
      b1 = ((r * c) >> 1);
      b2 = 2;
      b3 = a2 = r + c - 4;
      a3 = 2;
      a1 = b1 - a2 - a3;
   }    
   if (n <= b1) return 0;
   else if (r* c <= a1 + n) return 4 * n - r - c - ((r * c) << 1);
   else 
   {
      if (r * c <= a2 + n + a1) return (r * (c - 1) + c * (r - 1)) - 4 * a1 - (r * c - n - a1) * 3;
      else if (n <= b2 + b1) return ((n - b1)  << 1);
      else
      {
         n -= b1;
         int t = b2;
         if (n < t) t = n;
         t <<= 1;
         if (n > b2) return t + (n-b2)*3;
         else return t;
      }
   }
}

int main() 
{
    int tt;
    scanf("%d", &tt);  
    for (int ii = 1; ii <= tt; ++ii)
    {
        scanf("%d %d %d", &r, &c, &n);
        printf("Case #%d: %d\n", ii, solve());
    }
}
