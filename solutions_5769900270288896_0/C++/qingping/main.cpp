#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
int onenum(int x)
{
    int rnt=0;
    while(x)
    {
        rnt+=(x&1);
        x>>=1;
    }
    return rnt;
}

int main()
{
//    freopen("B-small-attempt0.in","r",stdin);
//    freopen("B-small-attempt0.out","w",stdout);
    int T;

    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        int n,r,c;
        scanf("%d%d%d",&r,&c,&n);
        int totnum=r*c;
        int limit = 1<<totnum;
        //cout<<limit<<endl;
        int ans=INF;
        for(int kind=0;kind<limit;kind++)
        {
            if(onenum(kind)!=n) continue;
            int rnt=0;
            for(int i=0;i<totnum;i++)
            {
                if(kind & (1<<i))
                {
                    if((i+1)%c!=0 && (kind & (1<<(i+1))))
                        rnt++;
                    if(i+c<totnum && (kind & (1<<(i+c))))
                        rnt++;
                }
            }
            ans=min(ans,rnt);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
