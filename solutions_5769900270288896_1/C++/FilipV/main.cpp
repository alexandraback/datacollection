#include <bits/stdc++.h>

using namespace std;

bool black(int x,int y,int r,int c)
{
    if(x<0||y<0||x>=r||y>=c)return false;
    return (x+y)%2==0;
}

bool black2(int x,int y,int r,int c)
{
    if(x<0||y<0||x>=r||y>=c)return false;
    return (x+y)%2==1;
}
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int solve(int r,int c,int n)
{
    int null=0;
    int one=0;
    int two=0;
    int three=0;
    int four=0;
    int sol=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(black(i,j,r,c))null++;
            else
            {
                int cnt=0;
                for(int k=0;k<4;k++)if(black(i+dx[k],j+dy[k],r,c))cnt++;
                if(cnt==1)one++;
                if(cnt==2)two++;
                if(cnt==3)three++;
                if(cnt==4)four++;
            }
        }
    }
    n-=min(n,null);
    sol+=min(n,one);
    n-=min(n,one);
    sol+=min(n,two)*2;
    n-=min(n,two);
    sol+=min(n,three)*3;
    n-=min(n,three);
    sol+=min(n,four)*4;
    n-=min(n,four);
    return sol;
}
int solve2(int r,int c,int n)
{
    int null=0;
    int one=0;
    int two=0;
    int three=0;
    int four=0;
    int sol=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(black2(i,j,r,c))null++;
            else
            {
                int cnt=0;
                for(int k=0;k<4;k++)if(black2(i+dx[k],j+dy[k],r,c))cnt++;
                if(cnt==1)one++;
                if(cnt==2)two++;
                if(cnt==3)three++;
                if(cnt==4)four++;
            }
        }
    }
    n-=min(n,null);
    sol+=min(n,one);
    n-=min(n,one);
    sol+=min(n,two)*2;
    n-=min(n,two);
    sol+=min(n,three)*3;
    n-=min(n,three);
    sol+=min(n,four)*4;
    n-=min(n,four);
    return sol;
}
int main()
{
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    int cas=1;
    while(t--)
    {
        int r,c,n;
        scanf("%d%d%d",&r,&c,&n);
        if(r%2==0||c%2==0)
        {
            printf("Case #%d: %d\n",cas++,solve(r,c,n));
        }
        else
        {

            printf("Case #%d: %d\n",cas++,min(solve(r,c,n),solve2(r,c,n)));
        }
    }
    return 0;
}
