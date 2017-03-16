#include<stdio.h>
#include<string.h>
#define maxxx(a,b) a>b?a:b
int main()
{
    int a[1010];
    int rat,minn;
    int cases,t,n;
    while(scanf("%d",&t)!=EOF)
    {
        cases=1;
        while(t--)
        {
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
            int  ans=0;
            for(int i=1;i<n;i++)
            {
                if(a[i]<a[i-1])
                {
                    ans+=(a[i-1]-a[i]);
                }
            }
            int ans2=0;
            int maxx=0;
            for(int i=1;i<n;i++)
            {
                if(a[i]<a[i-1])
                {
                    maxx=maxxx(maxx,a[i-1]-a[i]);
                }
            }
            //printf("%d\n",maxx);
            for(int i=0;i<n-1;i++)
            {
                if(a[i]-maxx>=0)
                {
                    ans2+=maxx;
                }
                else
                {
                    ans2+=a[i];
                }
                //printf("%d\n",ans2);
            }
            printf("Case #%d: %d %d\n",cases,ans,ans2);
            cases++;
        }
    }
    return 0;
}
