#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
const int maxn=1010;
int T,n,cas=1;
int a[maxn];
int main()
{
    freopen("A-l.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        int a1=0,r=0,a2=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i)
            {
                if (a[i-1]-a[i]>0) a1+=a[i-1]-a[i];
                if (r<a[i-1]-a[i]) r=a[i-1]-a[i];
            }
        }
        for (int i=0;i<n-1;i++) a2+=r<a[i]?r:a[i];
        printf("Case #%d: %d %d\n",cas++,a1,a2);
    }
    return 0;
}
