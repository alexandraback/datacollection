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
int T,n;
int a[20006];
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("A1.out","w",stdout);
    scanf("%d",&T);
    For(C,1,T)
    {
        scanf("%d",&n);
        int ans1=0,ans2=0;
        Rep(i,n)
            scanf("%d",&a[i]);
        int ma=0;
        For(i,1,n-1)
        {
            ans1+=max(0,a[i-1]-a[i]);
            ma=max(ma,a[i-1]-a[i]);
        }

        For(i,1,n-1)
        {
            ans2+=min(a[i-1],ma);
        }
        printf("Case #%d: %d %d\n",C,ans1,ans2);

    }

    return 0;
}
