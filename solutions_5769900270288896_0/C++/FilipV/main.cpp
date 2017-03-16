#include <bits/stdc++.h>

using namespace std;
int popcount(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=x%2;
        x/=2;
    }
    return ret;
}
bool mat[30][30];
int main()
{
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    int cas=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int r,c,n;
        scanf("%d%d%d",&r,&c,&n);
        int p=r*c;
        int sol=99999;
        for(int i=0;i<(1<<p);i++)
        {
            if(popcount(i)==n)
            {
                int cur=0;
                for(int x=0;x<30;x++)
                    for(int y=0;y<30;y++)
                        mat[x][y]=false;
                for(int x=1;x<=r;x++)
                {
                    for(int y=1;y<=c;y++)
                    {
                        mat[x][y]=((i&(1<<cur))>0);
                        cur++;
                    }
                }
                int sum=0;
                for(int x=1;x<=r;x++)
                {
                    for(int y=1;y<=c;y++)
                    {
                        if(mat[x][y]&&mat[x][y+1])sum++;
                        if(mat[x][y]&&mat[x+1][y])sum++;
                    }
                }



                sol=min(sol,sum);

            }

        }
        printf("Case #%d: %d\n",cas++,sol);
    }
    return 0;
}
