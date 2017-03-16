#include<bits/stdc++.h>
using namespace std;

int n,m,t,r,c;
int F[20][(1<<4)+10][20];
int a[(1<<4)+10];
int b[(1<<4)+10];

void init() {
    for(int i=0; i<(1<<4); i++) {
        int x=i;
        int y=0;
        while(x) {
            if(x&1) {
                b[i]++;
                if(y&1) a[i]++;
            }
            y=(x&1);
            x>>=1;
        }
    }
}
int solve() {
    if(r<c) swap(r,c);
    for(int i=0; i<=r; i++) for(int j=0; j<(1<<c); j++) for(int k=0; k<=n; k++) F[i][j][k]=10000;
    F[0][0][0]=0;
    for(int i=1; i<=r; i++) {
        for(int j=0; j<(1<<c); j++) {
            for(int k=0; k<=n; k++) {
                if(F[i-1][j][k]==10000) continue;
                for(int p=0; p<(1<<c); p++) {
                    if(b[p]+k<=n) {
                        int x=p&j;
                        int cnt=a[p];
                        while(x) {
                            if(x&1) cnt++;
                            x>>=1;
                        }
                        F[i][p][b[p]+k]=min(F[i][p][b[p]+k],F[i-1][j][k]+cnt);
                    }
                }
            }
        }
    }
    int ans=10000;
    for(int i=0; i<(1<<c); i++) ans=min(ans,F[r][i][n]);
    return ans;
}
int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);

    init();
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++) {
        scanf("%d%d%d",&r,&c,&n);
        int ans = solve();
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
