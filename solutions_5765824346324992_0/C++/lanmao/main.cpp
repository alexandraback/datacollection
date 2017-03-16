#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;
int gcd(int a,int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
int main()
{
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int b,n;
        scanf("%d%d",&b,&n);
        int now = 1 ;
        int a[10];
        for(int i=1;i<=b;i++)
        {
            scanf("%d",a+i);
            now =lcm(a[i],now);
        }
        int num = 0;
        for(int i=1;i<=b;i++)
        {
            num+=now/a[i];
        }
        n = n%num;
        if (n==0) n = num;
        int aa[10];
        for(int i=1;i<=b;i++) aa[i]=0;
        for(int i=1;i<=n;i++)
        {
           int minn=1100000;
           int id=0;
           for(int j=1;j<=b;j++)
           {
              if (minn>aa[j])
              {
                    minn = aa[j];
                    id=j;
                    now=j;
              }
           }
           aa[id] +=a[id];
        }
        printf("Case #%d: %d\n",cas++,now);
    }
}
