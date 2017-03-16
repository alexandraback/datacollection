#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
   int cas, ans, num, mark[32];

   scanf("%d",&cas);
   for (int k=1; k<=cas; ++k) {
      for (int i=1; i<=16; ++i) mark[i]=0;
      scanf("%d",&ans);
      --ans;
      for (int r=0; r<4; ++r)
         for (int c=0; c<4; ++c) {
            scanf("%d",&num);
            if (r==ans) ++mark[num];
         }
      scanf("%d",&ans);
      --ans;
      for (int r=0; r<4; ++r)
         for (int c=0; c<4; ++c) {
            scanf("%d",&num);
            if (r==ans) ++mark[num];
         }
      ans=-1;
      for (int i=1; i<=16; ++i) {
         if (mark[i]==2) {
            if (ans>=0) {ans=100; break;}
            else ans=i;
         }
      }
      printf("Case #%d: ",k);
      if (ans<0) printf("Volunteer cheated!\n");
      else if (ans>16) printf("Bad magician!\n");
      else printf("%d\n", ans);
   }

   return 0;
}
