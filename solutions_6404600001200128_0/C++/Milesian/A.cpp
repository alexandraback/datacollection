#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#define maxn 1020
using namespace std;
int T;
int mx,n;
int a[maxn];
int ans1,ans2;
int main()
{
    scanf("%d",&T);
    for(int ii=1;ii<=T;++ii)
    {
        mx=0;
        ans1=ans2=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            if(i>1)
            {
                mx=max(mx,a[i-1]-a[i]);
                ans1+=max(0,a[i-1]-a[i]);
            }
        }
        for(int i=2;i<=n;++i)
        {
            ans2+=min(mx,a[i-1]);
        }
        printf("Case #%d: %d %d\n",ii,ans1,ans2);
    }
    return 0;
}
