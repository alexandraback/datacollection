#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
using namespace std;
struct node
{
    int x,y;
} p[10005];
int cmp(node i,node j)
{
    return 1ll*i.x*j.y>1ll*i.y*j.x;
}
int cmp1(node i,node j)
{
    return 1ll*i.x*j.y>=1ll*i.y*j.x;
}
int x[10005],y[10005];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,ca=0;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; ++i)
            scanf("%d%d",&x[i],&y[i]);
        printf("Case #%d:\n",++ca);
        if (n==1)
        {
            puts("0");
            continue;
        }
        for (int i=1; i<=n; ++i)
        {
            int cnt=0;
            for (int j=1; j<=n; ++j)
                if (i!=j)
                {
                    p[++cnt].x=x[j]-x[i];
                    p[cnt].y=y[j]-y[i];
                }
            int right=cnt;
            while (right>=1&&p[right].x<0)
                right--;
            for (int j=1; j<=right; ++j)
                if (p[j].x<0)
                {
                    swap(p[j],p[right]);
                    while (right>=j&&p[right].x<0)
                        --right;
                }
            right=cnt;
            while (right&&p[right].x<0)
                --right;
            sort(p+1,p+right+1,cmp);
            sort(p+right+1,p+cnt+1,cmp);
            int ans=1<<29;
            for (int j=cnt+1; j<=2*cnt; ++j)
                p[j]=p[j-cnt];
            int left=2,temp=2;
            for (int j=1; j<=cnt; ++j)
            {
                while (left<j+cnt&&cmp(p[j],p[left]))
                    ++left;
                left=max(left,j+1);
                temp=max(temp,j+1);
                if (left==j+cnt)
                {
                    ans=0;
                    break;
                }
                ans=min(ans,left-j-1);
                while (temp<j+cnt&&cmp1(p[j],p[temp]))
                    ++temp;
                ans=min(ans,cnt-(temp-j));
            }
            printf("%d\n",ans);
        }
    }
}
