#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int a[1005],n,m;
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t,ret1=0,ret2=0,ca=0,k=0;
    scanf("%d",&t);
    while(t--)
    {
        ret1=m=0;
        ret2=k=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            m=max(m,a[i]);
        }
        for(int i=1;i<n;i++)
            ret1+=max(0,a[i-1]-a[i]);
        for(int i=1;i<n;i++)
            k=max(a[i-1]-a[i],k);
        for(int j=0;j<n-1;j++)
        {
            ret2+=min(a[j],k);
        }
        printf("Case #%d: %d %d\n",++ca,ret1,ret2);
    }
    return 0;
}
