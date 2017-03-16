#include<iostream>
#include<cstdio>
int a[1010];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j,n,m,ca,diff,first,second;
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++)
    {
        first=second=0;
        diff=-1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                first+=(a[i]-a[i+1]);
            }
            if(a[i]-a[i+1]>diff)
                diff=a[i]-a[i+1];
        }
        for(i=0;i<n-1;i++)
        {
            if(a[i]<=diff)
            {
                second+=a[i];
            }
            else
            {
                second+=diff;
            }
        }

        printf("Case #%d: %d %d\n",ca,first,second);
    }
    return 0;
}
