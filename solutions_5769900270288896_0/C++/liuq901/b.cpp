#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
bitset <10010> f[10010];
void fill(int &n,int i,int j)
{
    if (n==0 || f[i][j])
        return;
    f[i][j]=1;
    n--;
}
int calc(int R,int C,int n,int p)
{
    for (int i=1;i<=R;i++)
        f[i].reset();
    for (int i=1;i<=R;i++)
        for (int j=1;j<=C;j++)
            if ((i+j)%2==p)
                fill(n,i,j);
    fill(n,1,1);
    fill(n,R,1);
    fill(n,1,C);
    fill(n,R,C);
    for (int i=1;i<=R;i++)
    {
        fill(n,i,1);
        fill(n,i,C);
    }
    for (int i=1;i<=C;i++)
    {
        fill(n,1,i);
        fill(n,R,i);
    }
    for (int i=1;i<=R;i++)
        for (int j=1;j<=C;j++)
            fill(n,i,j);
    int ret=0;
    for (int i=1;i<=R;i++)
        for (int j=1;j<=C;j++)
        {
            if (!f[i][j])
                continue;
            if (i<R && f[i+1][j])
                ret++;
            if (j<C && f[i][j+1])
                ret++;
        }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int R,C,n;
        scanf("%d%d%d",&R,&C,&n);
        static int id=0;
        printf("Case #%d: %d\n",++id,min(calc(R,C,n,0),calc(R,C,n,1)));
    }
    return(0);
}

