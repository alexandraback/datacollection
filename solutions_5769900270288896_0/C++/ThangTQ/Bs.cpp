#include<bits/stdc++.h>

using namespace std;

int A[20][20], di[4]={0,1,0,-1}, dj[4]={1,0,-1,0}, f[20][20][400];
int M, N, P, res;

int getbit(int mask, int i)
{
    return ((mask>>(i-1))&1);
}

int countbit(int mask)
{
    int res = 0;
    for(int i=1; i<=M*N; i++) res+=getbit(mask,i);
    return res;
}

int ktr(int x, int y)
{
    if (x<1||y<1||x>M||y>N) return 0;
    return A[x][y];
}

void cal(int mask)
{
    int k = countbit(mask);
    if (f[M][N][k]==-1) f[M][N][k]=1e9;
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
            A[i][j]=getbit(mask,(i-1)*N+j);
    }
    int t = 0;
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        if (A[i][j]==1)
        {
            for(int k=0; k<4; k++)
                t+=ktr(i+di[k],j+dj[k]);
        }
    }
    f[M][N][k]=min(f[M][N][k],t/2);
}

void tinh()
{
    if (M>N) swap(M,N);
    if (f[M][N][P]!=-1)
    {
        res=f[M][N][P];
        return;
    }
    for(int i=0; i<(1<<(M*N)); i++)
        cal(i);
    res=f[M][N][P];
}

int main()
{
	freopen("test.inp","r",stdin); freopen("test.out","w",stdout);
	memset(f,255,sizeof(f));
	int T; scanf("%d",&T);
	for(int i=1; i<=T; i++)
    {
        scanf("%d%d%d",&M,&N,&P);
        tinh();
        printf("Case #%d: %d\n",i,res);
    }
	fclose(stdin); fclose(stdout);
	return 0;
}
