#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int n,test,x,y;
int a[1111];
int main()
{
    freopen("/Users/Dora/Desktop/ex/ex/x.in","r",stdin);
    freopen("/Users/Dora/Desktop/ex/ex/x.out","w",stdout);
    scanf("%d",&test);
    //printf("HelloWorld");
    for (int testnum=1; testnum<=test; ++testnum)
    {
        scanf("%d",&n);
        int sum=0,_max=0,ans,tmp;
        for (int i=0; i<n; ++i) scanf("%d",a+i);
        for (int i=1; i<n; ++i)
            if (a[i]<a[i-1])
            {
                sum+=a[i-1]-a[i];
                if (a[i-1]-a[i]>_max) _max = a[i-1] -a[i];
            }
        ans=_max;
        //if (_max%10==0) ans=_max/10; else ans=_max/10+1;
        tmp=0;
        for (int i=0; i<n-1; ++i)
            if (ans>=a[i]) tmp+=a[i]; else tmp+=ans;
        printf("Case #%d: %d %d\n",testnum,sum,tmp);
    }
}