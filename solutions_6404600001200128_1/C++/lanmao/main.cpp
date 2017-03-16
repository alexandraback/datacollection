#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n;
        int a[100000];
        scanf("%d",&n);
        int maxn =-1;
        for(int i=1;i<=n;i++)
            {scanf("%d",a+i);maxn=max(maxn,a[i]);}
        int ans1=0;
        int ans2=0;
        for(int i=2;i<=n;i++)
        {
            if (a[i]>=a[i-1])
                continue;
            else
                ans1+=a[i-1]-a[i];
        }
        //printf ("%d\n",ans1);
        int minn = 10000000;
        for(int sp=0;sp<=maxn+1;sp++)
        {
            int tmp=0;
            bool flag =true;
            for(int i=2;i<=n;i++)
            {

                    int tmp2 = a[i-1];
                    tmp2-=sp;
                    if(tmp2 > a[i]) {flag=false;break;}
                    else if (tmp2<=0)
                           tmp+=a[i-1];
                    else tmp+=sp;
            }
            if (!flag)continue;
            minn = min(tmp,minn);
        }
        ans2= minn;
        printf ("Case #%d: %d %d\n",cas++,ans1,ans2);
    }
    return 0;
}
