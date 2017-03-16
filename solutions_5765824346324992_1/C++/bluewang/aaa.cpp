#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int a[10005];
int main(int argc, char const *argv[])
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,ca=0,n=0;
    scanf("%d",&T);
    while(T--)
    {
        long long m;
        scanf("%d%lld",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        long long le=0,ri=100000000000000;
        while(ri-le)
        {
            long long mid=(le+ri)/2;
            long long tmp=0;
            for (int i=1;i<=n;i++)
                tmp+=mid/a[i]+((mid%a[i])!=0);
            if (tmp<m) le=mid+1;
            else ri=mid;
        }
        printf("Case #%d: ",++ca);
        for (int i=1;i<=n;i++)
        {
            if (a[i]==1) m-=le/a[i]-1;
            else if (le%a[i]<=1) m-=le/a[i];
                else m-=le/a[i]+1;
        }
        for (int i=1;i<=n;i++)
        {
            if (a[i]==1) m--;
            if ((le%a[i])==1) m--;
            if (!m)
            {
                printf("%d\n", i);
                break;
            }
        }

    }

    return 0;
}