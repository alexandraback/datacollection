#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cassert>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<utility>
#include<queue>
#include<stack>
#include<ctime>
#include<algorithm>
#define SZ 1005
using namespace std;
int a[SZ];
int main()
{
    freopen("Ain0.in","r",stdin);
    freopen("Aout.txt","w",stdout);
    int T,n;
    cin>>T;
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int ans1=0,ans2=0;
        for(int i=1;i<n;i++)
            if(a[i]<a[i-1])
                ans1+=a[i-1]-a[i];
        int rt=0;
        for(int i=1;i<n;i++)
        {
            rt=max(rt,a[i-1]-a[i]);
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i]<rt)
                ans2+=a[i];
            else
                ans2+=rt;
        }
        printf("Case #%d: %d %d\n",cas,ans1,ans2);
    }
    return 0;
}

