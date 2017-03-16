#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int r,c,n;
int dp[(1<<16)+5][20];

int calc(int mask,int rem)
{
    //cout<<mask<<" "<<rem<<endl;
    int &ret=dp[mask][rem];
    if(ret!=-1) return ret;
    if(rem==0) return 0;
    ret=r*c+10;
    for(int i=0;i<r*c;i++)
    {
        int x,y;
        if((mask & (1<<i))==0)
        {
            x=calc(mask | (1<<i),rem-1);
            y=0;
            for(int j=0;j<r*c;j++)
            {
                if((mask & (1<<j)))
                {
                    int ix=i/r,iy=i%r;
                    int jx=j/r,jy=j%r;
                    if(abs(ix-jx)+abs(iy-jy)==1) y++;
                }

            }
            ret=min(ret,x+y);
        }
    }
    return ret;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        cin>>r>>c>>n;
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %d\n",cs++,calc(0,n));
    }
    return 0;
}
