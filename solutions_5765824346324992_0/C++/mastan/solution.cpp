#include <cstdio>
#include <algorithm>

using namespace std;

int tc;

int n,m;
long long tme[1005];


int main()
{
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    scanf("%d",&tc);
    for (int it=1; it<=tc; it++)
    {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++)
            scanf("%lld",&tme[i]);
        long long bot=0;
        long long top=2*m*tme[1];
        long long tr;

        while (top>bot)
        {
            tr=(top+bot+1)/2;
            long long cnt=0;
            for (int i=1; i<=n; i++)
                cnt=cnt+(tr+tme[i]-1)/tme[i];
            //printf("%lld %lld\n",tr,cnt);
            if (cnt<m)
                bot=tr;
            else
                top=tr-1;
        }
        for (int i=1; i<=n; i++)
            m=m-(top+tme[i]-1)/tme[i];
        //printf(">>%lld %lld\n",top,m);
        int ret=-1;
        for (int i=1; i<=n; i++)
            if (top%tme[i]==0)
            {
                m--;
                if (m==0)
                    ret=i;
            }
        printf("Case #%d: %d\n",it,ret);
    }

}
