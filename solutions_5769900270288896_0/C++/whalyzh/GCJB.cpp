#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,t,r,c;
int dp[20][(1<<4)+10][20];
int a[(1<<4)+10];
int b[(1<<4)+10];

int main()
{
#ifdef Haha
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("B-small-attempt0 (1).out","w",stdout);
#endif // Haha
    for(int i=0;i<(1<<4);i++){
        int x=i;
        int y=0;
        while(x){
            if(x&1){
                b[i]++;
                if(y&1) a[i]++;
            }
            y=(x&1);
            x>>=1;
        }
    }
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        scanf("%d%d%d",&r,&c,&n);
        if(r<c) swap(r,c);
        for(int i=0;i<=r;i++) for(int j=0;j<(1<<c);j++) for(int k=0;k<=n;k++) dp[i][j][k]=10000;
        dp[0][0][0]=0;
        for(int i=1;i<=r;i++){
            for(int j=0;j<(1<<c);j++){
                for(int k=0;k<=n;k++){
                    if(dp[i-1][j][k]==10000) continue;
                    for(int p=0;p<(1<<c);p++){
                        if(b[p]+k<=n){
                            int x=p&j;
                            int cnt=a[p];
                            while(x){
                                if(x&1) cnt++;
                                x>>=1;
                            }
                            dp[i][p][b[p]+k]=min(dp[i][p][b[p]+k],dp[i-1][j][k]+cnt);
                        }
                    }
                }
            }
        }
        int ans=10000;
        for(int i=0;i<(1<<c);i++) ans=min(ans,dp[r][i][n]);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
