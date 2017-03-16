#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<climits>
#include<stack>
using namespace std;
typedef long long int ll;
ll dx[4]={0,1,-1,0};
ll dy[4]={1,0,0,-1};
ll r,c;
ll check(ll num)
{
    ll a=0,i,row,col,j;
    for(i=0;i<(r*c);i++)
    {
        if((num&(1<<i))==(1<<i))
        {
            row=i/c;
            col=i-((row)*c);
            //cout<<row<<" "<<col<<endl;
            for(j=0;j<4;j++)
            {
                if(row+dx[j]<r && row + dx[j]>=0 && col + dy[j]>= 0 && col + dy[j]<c)
                {
                    ll tmp=(row+dx[j])*c + col+dy[j];
                    if((num&(1<<(tmp)))==(1<<(tmp)))
                    a++;
                }
            }
        }
    }
    return (a/2);
}
int main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    ll tc,i,j,cnt,val,ans,t,n,v;
    cin>>tc;
    for(t=1;t<=tc;t++)
    {
        ans=1000000000;
        cin>>r>>c>>n;
        for(i=0;i<(1<<(r*c));i++)
        {
            cnt=0;
            v=1;
            for(j=0;j<(r*c);j++)
            {
                if((i&(1<<j))==(1<<j))
                {
                    cnt++;
                }
            }
            //cout<<endl;
            if(cnt==n)
            {
                val=check(i);
                //cout<<i<<" "<<val<<" "<<cnt<<endl;

                if(val<ans)
                    ans=val;
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}
