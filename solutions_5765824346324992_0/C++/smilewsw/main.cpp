#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
struct bab
{
    int id;
    int m;
    bool operator <(const bab& b)const
    {
        if(m!=b.m)
            return m<b.m;
        return id<b.id;
    }
}p[10000000];
int a[2000];
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
   freopen("output.txt","w",stdout);
    int T,n,b,num,sum;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        sum=1;
        scanf("%d %d",&b,&n);
        for(int i=1;i<=b;i++)
        {
            scanf("%d",&a[i]);
            sum*=a[i];
        }
        int cnt=0;
        for(int i=1;i<=b;i++)
        {
            for(int j=0;j<sum/a[i];j++)
            {
                p[cnt].id=i;
                p[cnt].m=a[i]*j;
                cnt++;
            }
        }
        sort(p,p+cnt);
        if(n%cnt==0)
            printf("Case #%d: %d\n",t,p[cnt-1].id);
        else
            printf("Case #%d: %d\n",t,p[n%cnt-1].id);
    }
    return 0;
}
