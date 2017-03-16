#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[17], gr[5][5];

int main(){
   int t, a1, a2;
   freopen("in.in", "r", stdin);
   freopen("out.out", "w", stdout);
   scanf("%d", &t);
   for (int ik = 1; ik<=t; ik++){
      memset(a, 0, sizeof(a));
      scanf("%d", &a2);
      for (int i =1; i<=4; i++)
         for (int j = 1; j<=4; j++){
            scanf("%d", &gr[i][j]);
            if (i==a2) a[gr[i][j]] = 1;
         }
      scanf("%d", &a1);
      int count = 0, ans;
      for (int i =1; i<=4; i++)
         for (int j = 1; j<=4; j++){
            scanf("%d", &gr[i][j]);
            if (i==a1 && a[gr[i][j]] == 1) {
               count++;
               ans = gr[i][j];
            }
         }
      printf("Case #%d: ", ik);
      if (count > 1) printf("Bad magician!\n");
      else if (count == 1) printf("%d\n", ans);
      else printf("Volunteer cheated!\n");
   }
   return 0;
}
