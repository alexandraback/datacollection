#include <cstdio>
#include <cstring>

using namespace std;
int mat[20][20],N,M,K,ans;
int sol[6][6];

void back(int x,int y,int cst,int crt)
{
    if(crt == K)
    {
        if(ans > cst)
        {
            ans = cst;
            ///memcpy(sol,mat,sizeof(mat));
        }
        return;
    }

    if(x > N || y > M)
        return;

    mat[x][y] = 1;
    int cst1 = 0;
    cst1 = mat[x][y-1] + mat[x-1][y];
    if(y < M)
    {
        mat[x][y] = 1;
        back(x,y+1,cst + cst1,crt + 1);
        mat[x][y] = 0;
        back(x,y+1,cst,crt);
        return;
    }
    if(y == M)
    {
        mat[x][y] = 1;
        if(x <= N)
            back(x+1,1,cst+cst1,crt + 1);
        mat[x][y] = 0;
        if(x <= N)
            back(x+1,1,cst,crt);
        return;
    }
}

void solve()
{
    scanf("%d%d%d",&N,&M,&K);
    memset(mat,0,sizeof(mat));
    back(1,1,0,0);
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int tst;
    scanf("%d",&tst);
    for(int i =1; i <= tst; ++i)
    {
        ans = 999999;
        solve();
        printf("Case #%d: %d\n",i,ans);

    }

    return 0;
}
