#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int T,R,C,N;
int ans;
bool F[100][100];

const int Gox[]={1,0,-1,0};
const int Goy[]={0,1,0,-1};


inline int Check(const int xx,const int yy)
{
    if (!F[xx][yy]) return 0;
    int ret=0;
    for (int k=0;k<4;k++)
        ret+= F[xx+Gox[k]][yy+Goy[k]] ? 1:0;
    return ret;
}
void DFS(int x,int y,int nown)
{
    if (x==R && y==C+1)
    {
        if (nown) return ;
        int nowans=0;
        for (int i=1;i<=R;i++)
            for (int j=1;j<=C;j++)
                nowans+=Check(i,j);
        ans=min(nowans,ans);
        return ;
    }
    if (y==C+1)
    {
        y=1;++x;
    }
    if (nown)
    {
        F[x][y]=true;
        DFS(x,y+1,nown-1);
    }
    F[x][y]=false;
    DFS(x,y+1,nown);

}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-lyz.out","w",stdout);
    scanf("%d",&T);
    for (int nowT=1;nowT<=T;nowT++)
    {
        scanf("%d %d %d",&R,&C,&N);
        ans=N*4;
        memset(F,0,sizeof F);
        DFS(1,1,N);
        printf("Case #%d: %d\n",nowT,ans/2);
    }
    return 0;
}
