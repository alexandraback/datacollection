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
#define N 100
using namespace std;

int d[20][20];

int get(int r,int c)
{
    int ans=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(d[i][j]==1)
    {
        if(d[i][j+1]==1) ans++;
        if(d[i+1][j]==1) ans++;
    }
    return ans;
}
int main()
{
     freopen("B-small-attempt0.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        int r,c,n;
        scanf("%d%d%d",&r,&c,&n);

        int m=r*c;

        int ans = (r-1)*c + r*(c-1);
        for(int i=0;i<(1<<m);i++)
        {
            int cnt=0;
            memset(d,0,sizeof d);

            for(int j=0;j<m;j++)
            {
                if(i & (1<<j))
                {
                    cnt++;
                    d[j/c][j%c]=1;
                }
            }

            if(cnt == n)
            {
                ans =min(ans,get(r,c));
            }

        }

        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
