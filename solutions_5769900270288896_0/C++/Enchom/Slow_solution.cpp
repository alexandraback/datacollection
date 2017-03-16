#include <iostream>
#include <stdio.h>
using namespace std;

int n,m,k;
int t;
bool grid[21][21];
int best=0;

void Try()
{
    int ctr=0;
    int i,j;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (i!=n)
            {
                if (grid[i][j] && grid[i+1][j])
                ctr++;
            }

            if (j!=m)
            {
                if (grid[i][j] && grid[i][j+1])
                ctr++;
            }
        }
    }

    if (ctr<best)
    best=ctr;

    return;
}

void Solve(int x,int y,int rem)
{
    if (rem==0)
    {
        Try();
        return;
    }

    if (y==m+1)
    {
        Solve(x+1,1,rem);
        return;
    }

    if (x==n+1)
    return;

    Solve(x,y+1,rem);

    grid[x][y]=true;

    Solve(x,y+1,rem-1);

    grid[x][y]=false;

    return;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-output.txt","w",stdout);

    int i;
    int test;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d %d",&n,&m,&k);

        best=999999;
        Solve(1,1,k);

        printf("Case #%d: %d\n",test,best);
    }

    return 0;
}
