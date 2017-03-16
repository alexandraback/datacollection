#include <stdio.h>
#include <iostream>
using namespace std;

int t,n;
int m[1010];
int ans1,ans2;

int main()
{
    int tt,i,j,k,tmp,beta;
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m[i]);
        }
        ans1=0;
        for(i=1;i<n;i++)
        {
            tmp=m[i]-m[i+1];
            if(tmp>0) ans1+=tmp;
        }
        beta=0;
        for(i=1;i<n;i++)
        {
            tmp=m[i]-m[i+1];
            if(tmp>beta) beta=tmp;
        }
        ans2=0;
        for(i=1;i<n;i++)
        {
            if(m[i]<beta) ans2+=m[i];
            else ans2+=beta;
        }
        printf("Case #%d: %d %d\n",tt,ans1,ans2);

    }

}
