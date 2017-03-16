#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int a[10005];
int main(int argc, char const *argv[])
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,ca=0,n=0;
    scanf("%d",&T);
    while(T--)
    {
        int ans;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("Case #%d: ", ++ca);
        ans=0;
        for (int i=2;i<=n;i++)
            if (a[i]<a[i-1]) ans+=a[i-1]-a[i];
        printf("%d ", ans);
        ans=0;
        int maa=0;
        for (int i=2;i<=n;i++)
            if (a[i]<a[i-1]) maa=max(maa,a[i-1]-a[i]);
        for (int i=1;i<=n-1;i++)
            ans+=min(maa,a[i]);
        printf("%d\n",ans );
    }

    return 0;
}