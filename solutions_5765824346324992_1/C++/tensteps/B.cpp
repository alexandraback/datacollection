#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define Rep(i,n) for (int i=0;i<(n);i++)
#define For(i,l,r) for (int i=(l);i<=(r);i++)
#define PB push_back
#define MP make_pair
int T,n,m,ans;
int a[20005];
long long l,r,mid;


bool ok(long long u)
{
    long long cnt=0;
    For(i,1,n)
        cnt+=(u-1)/a[i]+1;
    return cnt>=m;
}

int main()
{
    freopen("B-large (1).in","r",stdin);
    freopen("B2.out","w",stdout);
    scanf("%d",&T);
    For(C,1,T)
    {
        scanf("%d%d",&n,&m);
        For(i,1,n)
            scanf("%d",&a[i]);
        l=1; r=m*200000LL;
        while (l<r)
        {
            mid=l+r>>1LL;
            if (ok(mid)) r=mid;
                else l=mid+1;
        }


        int cur=0;
        For(i,1,n)
            cur+=(l-2)/a[i]+1;
        cur=max(cur,0);
//        cerr<<"l cur "<<l<<" "<<cur<<endl;

        For(i,1,n)
            if ((l-1)%a[i]==0)
            {
                cur++;
                if (cur==m)
                {
                    ans=i;
                    break;
                }
            }
        printf("Case #%d: %d\n",C,ans);
    }


    return 0;
}
