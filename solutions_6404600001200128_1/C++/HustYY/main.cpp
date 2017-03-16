#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;



int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n,m[1010],ans1,ans2;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",m+i);
        int s=0;
        for (int i=1;i<n;++i)
            s=max(s,m[i]-m[i+1]);
        ans1=ans2=0;
        for (int i=2;i<=n;++i)
            ans1+=max(0,m[i-1]-m[i]);
        for (int i=1;i<n;++i)
            ans2+=min(s,m[i]);
        printf("Case #%d: %d %d\n",cas,ans1,ans2);
    }
    return 0;
}
