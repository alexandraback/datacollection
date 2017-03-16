#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define eps 1e-8
#define db double
#define rt return
#define cn const
#define op operator
#define N 1010
using namespace std;

int d[N];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);

    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++)
              scanf("%d",&d[i]);

        printf("Case #%d: ",ca);

        int ans=0;

        for(int i=0;i<n-1;i++)
              if(d[i]>d[i+1]) ans += d[i] - d[i+1];

        printf("%d ",ans);

        int temp=0;

        for(int i=0;i<n-1;i++)
            if(d[i]>d[i+1])
        {
            temp = max(temp,d[i]-d[i+1]);
        }

        ans=0;
         for(int i=0;i<n-1;i++)
         ans += min(d[i],temp);

         printf("%d\n",ans);
    }
    return 0;
}

