#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("inp.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,c=1,i,j,k,l,n,m,ans,a[10001],ans1,mx;
    scanf("%d",&t);
    //printf("%d\n",t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

//        printf("%d\n",n);
//        for(i=0;i<n;i++)
//            printf("%d ",a[i]);
//        printf("\n");

        ans=ans1=0;
        for(i=1;i<n;i++)
            ans=ans+max(0,a[i-1]-a[i]);
        mx=-1;
        for(i=1;i<n;i++)
            if(a[i-1]-a[i]>mx)
                mx=a[i-1]-a[i];
        for(i=0;i<n-1;i++)
        {
            if(a[i]<mx)
                ans1=ans1+a[i];
            else
                ans1+=mx;
        }
        printf("Case #%d: %d %d\n",c,ans,ans1);
        c++;
    }
    return 0;
}
