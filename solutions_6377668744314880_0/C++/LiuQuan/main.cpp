#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long LL;
using namespace std;

const int N=3333;
LL x[N],y[N];
int n,T,cas=0;
int ans[N];

int main(){
    freopen("C-small-attempt1.in","rb",stdin);
    freopen("data.out","wb",stdout);
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1; i<=n; i++){
            scanf("%I64d%I64d",&x[i],&y[i]);
            ans[i]=N+1;
        }
        for(int i=1; i<n; i++)
            for (int j=i+1; j<=n; j++){
                int k1=0,k2=0;
                LL vx1=x[j]-x[i],vy1=y[j]-y[i];
                for (int k=1; k<=n; k++){
                    if (k==i || k==j) continue;
                    LL vx2=x[k]-x[i],vy2=y[k]-y[i];
                    if (vx1*vy2-vx2*vy1>0) k1++;
                    if (vx1*vy2-vx2*vy1<0) k2++;
                }
                if (k1>k2) swap(k1,k2);
                ans[i]=min(ans[i],k1);
                ans[j]=min(ans[j],k1);
            }
        if (n==1) ans[1]=0;

        printf("Case #%d:\n",++cas);
        for (int i=1; i<=n; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
