#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
#define ll long long

using namespace std;

int r,c,n;
bool map[16][16] = {0};
int ans = INT_MAX;

int cal()
{
    int run = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j])
            {
                if(i!=0)
                {
                    if(map[i-1][j]) run++;
                }
                if(j!=c-1)
                {
                    if(map[i][j+1]) run++;
                }
            }
        }
    }
    return run;
}

void combi(int rr,int cc,int d)
{
    if(d==n)
    {
        ans = min(ans, cal());
//        cout << "ans " << ans << endl;
        return ;
    }
    for(int i=rr;i<r;i++)
    {
        int j = cc;
        if(i!=rr) j=0;
        for(;j<c;j++)
        {
            if(!map[i][j])
            {
                map[i][j] = true;
                combi(i,j,d+1);
                map[i][j] = false;
            }
        }
    }
}

void clean()
{
    ans = INT_MAX;
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++) map[i][j] = false;
}

int main()
{
    int t,tt;
    scanf("%d",&tt);
    t = 1;
    while(t<=tt)
    {
        scanf("%d %d %d",&r,&c,&n);
        clean();
        combi(0,0,0);
        printf("Case #%d: %d\n",t,ans);
        t++;
    }
    return 0;
}
