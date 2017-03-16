#include <cstdio>
#include <algorithm>
using namespace std;

int f(int r, int c)
{
   if(r%2 == 0)
      return c - 2;
   else
      return 2*((c-1)/2);
}

int main()
{
   int T;
   scanf("%d", &T);
   for(int _i=1; _i<=T; _i++)
   {
      int r, c, n;
      scanf("%d%d%d", &r, &c, &n);
      int t = r*(c-1) + c*(r-1);
      int m = r*c - n;
      int nt = (max(0, r-2)*max(0, c-2));

      if(m <= (nt + 1)/2)
      {
         t -= 4*m;
      }
      else
      {
         int nint = nt/2;
         t -= 4*nint;
         m -= nint;
         int nbord = f(r, c) + f(c, r);
         if(m <= nbord)
         {
            t -= 3*m;
         }
         else
         {
            t -= 3*nbord;
            m -= nbord;
            while(m > 0 && t > 0)
            {
               t -= 2;
               m--;
            }
         }
      }
      if(t < 0) t = 0;
      printf("Case #%d: %d\n",_i, t);
   }
   return 0;
}
