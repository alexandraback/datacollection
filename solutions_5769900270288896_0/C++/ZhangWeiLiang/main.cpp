# include<cstdio>
# include<iostream>
# include<vector>
# include<cstring>

using namespace std;

# define N 1000010
int dp[N];

int r,c,n;

int field[20][20];
int solve()
{
    int all=r*c;
    int res=0x3f3f3f3f;
    for(int s=0;s<(1<<all);s++)
    {
        memset(field,0,sizeof(field));
        int cnt=0;
        for(int i=0;i<all;i++)
        {
            if(s&(1<<i))    cnt++;
        }
        if(cnt != n)    continue;
        for(int i=0;i<all;i++)
        {
            if(s&(1<<i))    field[i/c][i%c]=1;
        }
        cnt=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)    if(field[i][j])
            {
                if(j+1<c && field[i][j+1])  cnt++;
                if(i+1<r && field[i+1][j])  cnt++;
            }
        }
        res=min(res,cnt);
    }
    return res;
}
int main()
{
    //freopen("B-small-attempt2.in","r",stdin);
    //freopen("out.out","w",stdout);
    int test;scanf("%d",&test);
    for(int T=1;T<=test;T++)
    {
        scanf("%d%d%d",&r,&c,&n);
        printf("Case #%d: %d\n",T,solve());
    }
    return 0;
}
