#include <bits/stdc++.h>

using namespace std;

int n,a[1005];

int main()
{
    int i,j,k,t,T,ret=0,ret2,mx;

    freopen("A-large.in","r",stdin);
    freopen("A-large.txt","w",stdout);

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {

        scanf("%d",&n);

        for(i=1;i<=n;i++) scanf("%d",&a[i]);

        for(mx=ret2=ret=0,i=2;i<=n;i++){

            if(a[i]>=a[i-1]) continue;

            ret+=a[i-1]-a[i];
            mx=max(mx,a[i-1]-a[i]);
        }

        for(i=1;i<n;i++){

            ret2+=min(a[i],mx);

        }

        printf("Case #%d: %d %d\n",t,ret,ret2);

    }

    return 0;
}
