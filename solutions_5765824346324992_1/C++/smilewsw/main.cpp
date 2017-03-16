#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int a[2000],b;
long long bi_search(int n,long long minn,long long maxn)
{
    long long left=minn*(n-b)/b,right=maxn*n+1,mid;
    while(left<right)
    {
        mid=left+(right-left)/2;
        long long cnt=0;
        for(int i=1;i<=b;i++)
        {
            if(mid%a[i]==0)
                cnt+=mid/a[i];
            else
                cnt+=mid/a[i]+1;
        }
        if(cnt<n)
            left=mid+1;
        else
            right=mid;
      //  printf("mid%I64d left%I64d\n",mid,left);
    }
    return left;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n;
    long long maxn,minn=10000000,time;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        maxn=0;
        scanf("%d %d",&b,&n);
        for(int i=1;i<=b;i++)
        {
            scanf("%d",&a[i]);
            if(maxn<a[i])
                maxn=a[i];
            if(minn>a[i])
                minn=a[i];
        }
        time=bi_search(n,minn,maxn);
        time--;
       // printf("time%I64d\n",time);
        long long cnt=0;
        for(int i=1;i<=b;i++)
        {
            if(time%a[i]==0)
                cnt+=time/a[i];
            else
                cnt+=time/a[i]+1;
        }
      //  printf("cnt%d\n",cnt);
        cnt=n-cnt;
        for(int i=1;i<=b;i++)
        {
            if(time%a[i]==0)
            {
                cnt--;
                if(cnt==0)
                {
                    printf("Case #%d: %d\n",t,i);
                    break;
                }
            }
        }
    }
    return 0;
}
