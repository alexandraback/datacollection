#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int solve(int r,int c,int n)
{
    if(n==0) return 0;
    int N = (r*c) , M[r][c];
    int i,j,k,x,y,cnt=0,ret=1000000000;
    for(i=0;i<(1<<N);i++)
    {
        if(__builtin_popcount(i)==n)
        {
            for(j=0;j<r;j++) for(k=0;k<c;k++) M[j][k]=0;
            x=y=0;
            for(j=0;j<N;j++)
            {
                if( (i&(1<<j)) != 0)
                {
                    M[x][y]=1;
                }
                if(y+1<c) y = y+1;
                else{
                    x=x+1;
                    y=0;
                }
            }
            cnt = 0;
            for(j=0;j<r;j++)
            {
                for(k=0;k<c;k++)
                {
                    if(M[j][k]==1)
                    {
                        if(j+1<r && M[j+1][k]==1) cnt++;
                        if(k+1<c && M[j][k+1]==1) cnt++;
                    }
                }
            }
            ret = min(ret,cnt);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Users/Ayur/Downloads/B-small-attempt0.in","r",stdin);
    freopen("/Users/Ayur/Downloads/B-small-output.txt","w",stdout);
    int t,tt,r,c,n;
    cin>>tt;
    for(t=1;t<=tt;t++)
    {
        cin>>r>>c>>n;
        cout<<"Case #"<<t<<": "<<solve(r,c,n)<<"\n";
    }
    
    
    return 0;
}