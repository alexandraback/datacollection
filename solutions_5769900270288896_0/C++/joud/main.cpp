# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
# include <ios>
# include <vector>
using namespace std;
bool mp[17][17];
int mn;
int n;
void calc(int r,int c)
{
    bool vis[17][17]={0};
    int num=0;
    int now=0;
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            if (mp[i][j]) num++;
            if (vis[i][j]==0 && mp[i][j])
            {
                vis[i][j]=1;
                if (j+1<c && vis[i][j+1]==0 && mp[i][j+1])
                    now++;
                if (i+1<r && vis[i+1][j]==0 && mp[i+1][j])
                    now++;
                if (j-1>=0 && vis[i][j-1]==0 && mp[i][j-1])
                    now++;
                if (i-1>=0 && vis[i-1][j]==0 && mp[i-1][j])
                    now++;
            }
        }
    }
    if (num==n)
        mn=min(mn,now);
}
void solve(int r,int c,int i,int j)
{
    if (i==r)
    {
        calc(r,c);
    }
    else
    {
        mp[i][j]=1;
        if (j==c-1)
            solve(r,c,i+1,0);
        else
            solve(r,c,i,j+1);
        mp[i][j]=0;
        if (j==c-1)
            solve(r,c,i+1,0);
        else
            solve(r,c,i,j+1);
    }
}
int main()
{
   freopen("out.txt","w",stdout);
   int t;
cin>>t;
   for (int gogo=1;gogo<=t;gogo++)
   {
       int r,c;
       mn=1000000;
       cin>>r>>c;
       cin>>n;
       solve(r,c,0,0);
       cout<<"Case #"<<gogo<<": "<<mn<<endl;
   }
}
