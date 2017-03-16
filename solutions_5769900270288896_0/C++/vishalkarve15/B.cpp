#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long

int a[20][20];
int Set[1<<17];
int r,c,n;
int num;

int setbits(int in)
{
    int cnt=0;
    while(in)
    {
        cnt+=(in&1);
        in>>=1;
    }
    return cnt;
}

int calc()
{
    int ret=0;
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    {
        if(!a[i][j])
            continue;
        if(a[i+1][j])
            ret++;
        if(a[i][j+1])
            ret++;
    }
    return ret;
}

int main()
{
    int x=(1<<17);

    for(int i=0;i<x;i++)
        Set[i]=setbits(i);

    int t;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++)
    {
        memset(a,0,sizeof a);
        int ans=INT_MAX;
        scanf("%d%d%d",&r,&c,&n);

        num=r*c;
        int comb=(1<<num);
        for(int i=0;i<comb;i++)
        {
            if(Set[i]!=n)
                continue;
            for(int j=0;j<num;j++)
            {
                if((i>>j)&1)
                    a[j/c][j%c]=1;
                else
                    a[j/c][j%c]=0;
            }
            int scor=calc();
            if(scor<ans)
                ans=scor;
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
