#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[10005];
int main()
{
    int T;
    freopen("input.in","r",stdin);
    freopen("output.in","w",stdout);
    scanf("%d",&T);
    int k=0;
    int n;
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int ans1=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            ans1+=(a[i-1]-a[i]);
        }
        int ma=0;
        int ans2=0;
        for(int i=1;i<n;i++)
        {
            ma=max(ma,a[i-1]-a[i]);
        }
        //printf("%d\n",ma);
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>ma)
            ans2+=ma;
            else
            ans2+=a[i];
        }
        printf("Case #%d: %d %d\n",++k,ans1,ans2);
    }
    return 0;
}
