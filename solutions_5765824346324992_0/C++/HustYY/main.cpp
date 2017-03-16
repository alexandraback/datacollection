#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long b,m[1010],same,Min;

long long calc(long long d)
{
    long long ret=0;
    Min=1000000000000000ll;
    for (int i=1;i<=b;++i)
    {
        if (d%m[i]<Min) same=1,Min=d%m[i];
        else if (d%m[i]==Min) ++same;
        ret+=d/m[i]+1;
    }
    return ret;
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    long long n;
    int t,ans;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%I64d%I64d",&b,&n);
        for (int i=1;i<=b;++i)
            scanf("%I64d",m+i);
        long long l=0,r=1000000000000000ll;
        while (l<=r)
        {
            long long mid=(l+r)>>1,tmp=calc(mid);
            if (tmp>=n&&tmp-same<n)
            {
                for (int i=b;i>=1;--i)
                    if (mid%m[i]==Min)
                    {
                        if (tmp==n)
                        {
                            ans=i;
                            break;
                        }
                        --tmp;
                    }
                break;
            }
            if (tmp<n) l=mid+1;
            else r=mid-1;
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
