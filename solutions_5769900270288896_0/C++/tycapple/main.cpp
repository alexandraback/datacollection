#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
using namespace std;
bool visit[20][20];
int s;
int r,c,n;
void dfs(int x,int y,int m)
{
    if(m==n)
    {
        int s1=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(visit[i][j]==true)
                {
                    if(visit[i+1][j]==true)
                        s1++;
                    if(visit[i][j+1]==true)
                        s1++;
                }
            }
        }
        s=min(s,s1);
        return;
    }
    if(x>r)
        return;
    int x1,y1;
    x1=x;
    y1=y+1;
    if(y1>c)
    {
        y1=1;
        x1++;
    }
    visit[x][y]=true;
    dfs(x1,y1,m+1);
    visit[x][y]=false;
    dfs(x1,y1,m);
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        cin>>r>>c>>n;
        memset(visit,false,sizeof(visit));
        s=1<<30;
        dfs(1,1,0);
        cout<<s<<endl;
    }
    return 0;
}
