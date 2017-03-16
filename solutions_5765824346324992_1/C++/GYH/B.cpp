#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF = 1e12;
const int maxn = 1000+10;
LL M[maxn];
int b;
LL n;


LL cal(LL t)
{
    LL cnt = 0;
    for(int i = 0;i < b;++i)
        cnt += t / M[i] + (LL)(t%M[i] != 0);
     return cnt;
}


int main()
{
    //freopen("./test.txt","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("tt.out","w",stdout);
    int kase;
    scanf("%d",&kase);
    for(int z = 1;z <= kase;++z)
    {
        scanf("%d %lld",&b,&n);
        for(int i = 0;i < b;++i)
            scanf("%lld",&M[i]);
        LL L = 0,R = INF;
        while(L <= R)
        {
            LL mid = (L+R)/2;
            if(cal(mid) < n) L = mid+1;
            else   R = mid-1;
        }
        while(cal(R) == n)
            R--;
        int res = 0,now = cal(R);
        for(int i = 0;i < b;++i)
        {
            if(R % M[i] == 0)
            {
                now++;
                if(now == n)
                {
                    res = i+1;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",z,res);
    }
    return 0;
}
