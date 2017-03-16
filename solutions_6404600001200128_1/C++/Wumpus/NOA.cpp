#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000+10;
int save[maxn];
int n;
int main()
{
    freopen("./A-large.in","r",stdin);
    freopen("./a.out","w",stdout);
    int kase;
    scanf("%d",&kase);
    for(int z = 1;z <= kase;++z)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;++i)
            scanf("%d",&save[i]);
        int res1 = 0;
        int rate = 0;
        for(int i = 1;i < n;++i)
            if(save[i] < save[i-1])
            {
                res1 += save[i-1] - save[i];
                rate = max(rate,save[i-1]-save[i]);
            }
        int res2 = 0;
        for(int i = 1;i < n;++i)
        {
            res2 += min(save[i-1],rate);
        }
        printf("Case #%d: %d %d\n",z,res1,res2);
    }
    return 0;
}
