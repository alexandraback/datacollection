#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int t;
int n,m,k;
bool black[10011][10011];

int BlackNeighbours(int x,int y)
{
    int ans=0;

    if (black[x+1][y])
    ans++;
    if (black[x-1][y])
    ans++;
    if (black[x][y+1])
    ans++;
    if (black[x][y-1])
    ans++;

    return ans;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large-output.txt","w",stdout);

    int test;
    int i,j;
    int chess;
    int ctr;
    int themin;
    pair<int,int> themincell;
    int ans=0,ans2=0;
    int orgk;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        fprintf(stderr,"%d test\n",test);
        scanf("%d %d %d",&n,&m,&k);

        orgk=k;

        chess=(n*m)/2;

        if ( (n*m)%2==1 )
        chess++;

        if (k<=chess)
        {
            printf("Case #%d: 0\n",test);
            continue;
        }

        ///

        for (i=0;i<=n+1;i++)
        {
            for (j=0;j<=m+1;j++)
            {
                black[i][j]=false;
            }
        }

        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                if ( (i+j)%2==1 )
                {
                    black[i][j]=true;
                    k--;
                }
            }
        }

        ans=0;
        while(k>0)
        {
            themin=999999999;
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=m;j++)
                {
                    if (!black[i][j])
                    {
                        ctr=BlackNeighbours(i,j);

                        if (ctr<themin)
                        {
                            themin=ctr;
                            themincell=make_pair(i,j);
                        }
                    }
                }
            }

            k--;
            ans+=themin;
            black[ themincell.first ][ themincell.second ]=true;
        }

        ///

        k=orgk;

        ///

        for (i=0;i<=n+1;i++)
        {
            for (j=0;j<=m+1;j++)
            {
                black[i][j]=false;
            }
        }

        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                if ( (i+j)%2==0 )
                {
                    black[i][j]=true;
                    k--;
                }
            }
        }

        ans2=0;
        while(k>0)
        {
            themin=999999999;
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=m;j++)
                {
                    if (!black[i][j])
                    {
                        ctr=BlackNeighbours(i,j);

                        if (ctr<themin)
                        {
                            themin=ctr;
                            themincell=make_pair(i,j);
                        }
                    }
                }
            }

            k--;
            ans2+=themin;
            black[ themincell.first ][ themincell.second ]=true;
        }

        ///

        if (ans<ans2)
        printf("Case #%d: %d\n",test,ans);
        else
        printf("Case #%d: %d\n",test,ans2);
    }

    return 0;
}
