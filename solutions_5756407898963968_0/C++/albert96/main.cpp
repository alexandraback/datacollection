#include <iostream>
#include <cstdio>
using namespace std;
const int N = 4;

int mark[ (N+5) *( N+5) ];
int main()
{
   //freopen("A-small-attempt0.in", "r", stdin);
  // freopen("A-small-attempt0.out", "w", stdout);
   int T = 0, te = 0;
   scanf("%d", &T);
   while(T--)
   {
      ++ te;
      int r;
      for(int i = 1; i <= N*N; ++ i)
         mark[i] = 0;
      for(int j = 1; j <= 2; ++ j)
      {
         scanf("%d", &r);
         for(int i = 1; i <= N; ++ i)
         {
            for(int j = 1; j <= N; ++ j)
            {
               int u;
               scanf("%d", &u);
               if(i==r)
               ++mark[ u ];
            }
         }
      }
      int qa = 0, po = 0;
      for(int i = 1; i <= N*N; ++ i)
      {
         if(mark[i]==2)
         {
            ++ qa;
            po = i;
         }
      }
      if(qa==1)
      {
         printf("Case #%d: %d\n", te, po);
      }
      else
      if(qa > 1)
      {
         printf("Case #%d: Bad magician!\n", te);
      }
      else
      {
         printf("Case #%d: Volunteer cheated!\n", te);
      }
   }
   return 0;
}
