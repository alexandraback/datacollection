#include<stdio.h>
#include<algorithm>
using namespace std;
int s[1007];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum=0,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&s[i]);
        int maxx=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]>=s[i+1])sum+=(s[i]-s[i+1]);
            maxx=max(maxx,s[i]-s[i+1]);
        }
        for(int i=1;i<n;i++)
            if(s[i]>maxx)ans+=maxx;
            else ans+=s[i];
        printf("Case #%d: %d %d\n",cas++,sum,ans);
    }
}
