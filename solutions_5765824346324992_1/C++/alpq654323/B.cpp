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
long long L,R,mid,X,MIN;
int a[1005],n,m,_,T,i;
long long OK(long long x)
{
    long long sum=0;
    for (int i=1; i<=n; i++) sum+=x/a[i]+(x%a[i]!=0);
    return sum;
}
struct node {int x,y;} t[10005];
int cmp(node i,node j) {return i.x<j.x || i.x==j.x &&i.y<j.y;}
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        _++; printf("Case #%d: ",_);
        scanf("%d%d",&n,&m);
        for (i=1; i<=n; i++) scanf("%d",&a[i]);
        L=0; R=(long long)100000*1000000000; mid=(L+R)/2;
        while (L<=R)
        {
            if (OK(mid)>=m) {R=mid-1; mid=(L+R)/2;} else
                {
                    L=mid+1;
                    mid=(L+R)/2;
                }
        }
        L--; X=OK(L); for (i=1; i<=n; i++) {t[i].x=a[i]-L%a[i],t[i].y=i; if (t[i].x==a[i]) t[i].x=0;}
        sort(t+1,t+n+1,cmp); printf("%d\n",t[m-X].y);
    }
    return 0;
}
