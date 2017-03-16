#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
    int x,y;
}a[20];
int main(int argc, char const *argv[])
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,ca=0,n=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d %d",&a[i].x,&a[i].y);
        printf("Case #%d:\n", ++ca);
        if (n<=3)
        {
            for (int i=1;i<=n;i++)
                puts("0");
            continue;
        }
        for (int i=1;i<=n;i++){
            int ans=n;
            for (int j=1;j<=n;j++)
            {
                int cnt=0;
                if (i==j) continue;
                for (int k=1;k<=n;k++)
                {
                    if (k==i||k==j) continue;
                    if (((long long)(a[k].x-a[i].x)*(a[j].y-a[i].y)-(long long)(a[k].y-a[i].y)*(a[j].x-a[i].x))<0)
                        cnt++;
                }
                ans=min(ans,cnt);
            }
            printf("%d\n",ans );
        }
    }
    return 0;
}