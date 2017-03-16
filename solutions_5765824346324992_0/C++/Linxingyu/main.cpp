#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n,test,x,y,m;
int a[1111];

int main()
{
    freopen("/Users/Dora/Desktop/ex/ex/x.in","r",stdin);
    freopen("/Users/Dora/Desktop/ex/ex/x.out","w",stdout);
    scanf("%d",&test);
    //printf("HelloWorld");
    for (int testnum=1; testnum<=test; ++testnum)
    {
        scanf("%d %d",&n,&m);
        for (int i=0; i<n; ++i) scanf("%d",a+i);
        long long l=0, r=1e16,mid,ans=r+1,sum=0;
        while (l<=r)
        {
            mid=(l+r)>>1;
            sum=0;
            for (int i=0; i<n; ++i) sum+=mid/a[i]+1;
            if (sum>=m)
            {
                if (mid<ans) ans=mid;
                r=mid-1;
            } else l=mid+1;
        }
        int rank=0;
        for (int i=0; i<n; ++i)
            if (ans % a[i]) m=m-int(ans/a[i])-1;
            else m-=ans/a[i];
        for (int i=0; i<n; ++i)
        {
            if (ans % a[i] ==0) --m;
            if (m==0) {rank=i+1; break;}
        }
        printf("Case #%d: %d\n",testnum,rank);
    }
}