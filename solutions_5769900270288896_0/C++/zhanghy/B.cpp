#include <bits/stdc++.h>

using namespace std;

int T,N,R,C;

int main() {
    freopen("B.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%d",&T);
    for (int kase = 1;kase <= T; kase++) {
           scanf("%d%d%d",&R,&C,&N);
           int w = R*C,a[R+1][C+1],ans = R*C*2;
           for (int i =1;i <= R; i++)
                   for (int j = 1;j <= C; j++) a[i][j] = 0;
           for (int i = 0;i < (1<<w); i++) {
                  int cnt = 0,wp = 0;
                  for (int j = 1;j <= R; j++) {
                         for (int k = 1;k <= C; k++) {
                                if ((1<<cnt)&i) {
                                    a[j][k] = i;
                                    wp++;
                                }
                                cnt++;
                         }
                  }
                  if (wp != N) continue;
                  int cnp =0;
                  for (int j = 1;j <= R; j++)
                         for (int k = 1;k <= C; k++) {
                                if (a[j][k] != i || a[j][k] == 0) continue;
                                if (j+1 <= R && a[j+1][k] == a[j][k]) cnp++;
                                if (k+1 <= C && a[j][k+1] == a[j][k]) cnp++;
                         }
                   ans = min(ans,cnp);
            }
            printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
