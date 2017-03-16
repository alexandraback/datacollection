#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
#define N 200000
#define M 1001
#define mm 100007
#define ll long long
int A,B;
int b,n,a[1001],ans;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int T,cas=0;
    cin>>T;
    while (T--)
    {
        scanf("%d",&n);
        int sp=0,ans1=0,ans2=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            int dc=a[i-1]-a[i];
            if (dc>0)
            {
                ans1+=dc;
                sp=max(sp,dc);
            }
        }
    //    cout<<sp<<endl;
        for (int i=1;i<n;i++)
        {
            ans2+=min(sp,a[i]);
        }
        printf("Case #%d: %d %d\n",++cas,ans1,ans2);
    }
}
