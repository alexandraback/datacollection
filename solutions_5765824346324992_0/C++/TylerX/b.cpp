#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ull;
ull num[1010];
int main()
{
    int T,cas=1;
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        ull b,n;
        scanf("%lld%lld",&b,&n);
        for(int i=1;i<=b;i++)
            scanf("%lld",&num[i]);
        ull L=0,R=(n+10)*100000;
        ull mL,Maxtot=-1;
        while(R-L>1)
        {
            //printf("%lld %lld",L,R);
            ull mid=(R-L)/2+L;
            ull tot=b;
            for(int i=1;i<=b;i++)
            {
                tot+=mid/num[i];
            }
            //printf(" %lld %lld\n",mid,tot);
            if(tot<n)   L=mid+1;
            else if(tot>=n) R=mid;
        }
        int ans;
        while(1)
        {
            ans=b+10;
            ull tot=0;
            for(int i=1;i<=b;i++)
            {
                tot+=L/num[i];
                if(L%num[i])    ++tot;
            }
            for(int i=1;i<=b;i++)
                if(L%num[i]==0)
                {
                    ++tot;
                    if(tot==n)
                    {
                        ans=i;
                        break;
                    }
                }
            if(tot>=n&&ans!=b+10)   break;
            ++L;
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
