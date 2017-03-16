#include <cstdio>

using namespace std;

int T,total,n,m,num,sol,ones,mapa[20][20],cur,ind;

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("BBB.out","w",stdout);
    scanf("%d",&T);
    for (int t=1; t<=T; t++) {
        scanf("%d %d %d",&n,&m,&num);
        total=n*m;
        sol=1000000;
        for (int mask=0; mask<(1<<total); mask++) {
            ones=0;
            for (int bit=0; bit<total; bit++) if (mask & (1<<bit)) ones++;
            if (ones!=num) continue;
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    ind=(i-1)*m+j-1;
                    if (mask & (1<<ind)) mapa[i][j]=1;
                    else mapa[i][j]=0;
                }
            }
            cur=0;
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    if (i<n && mapa[i][j] && mapa[i+1][j]) cur++;
                    if (j<m && mapa[i][j] && mapa[i][j+1]) cur++;
                }
            }
            if (cur<sol) sol=cur;
        }
        printf("Case #%d: %d\n",t,sol);
    }

    return 0;
}
