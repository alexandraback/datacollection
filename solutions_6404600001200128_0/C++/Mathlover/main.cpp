#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<vector>
#include<time.h>
using namespace std;
int m[10005];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,ca=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",m+i);
        int ans=0;
        int now=m[0];
        for(int i=1;i<n;++i)
            if(m[i]>now)
                now=m[i];
            else ans+=now-m[i],now=m[i];
        int ans1=0;
        int v1=0;
        for(int i=1;i<n;++i)
            v1=max(v1,m[i-1]-m[i]);
        //printf("%d\n",v1);
        for(int i=1;i<n;++i)
            if(m[i-1]-m[i]==v1)
                ans1+=m[i-1]-m[i];
            else if(m[i-1]<v1)
                ans1+=m[i-1];
            else ans1+=v1;
        printf("Case #%d: %d %d\n",++ca,ans,ans1);
    }
}
