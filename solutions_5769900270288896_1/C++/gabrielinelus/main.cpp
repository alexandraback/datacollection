#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int N,M,K;
int DP[5],best;

void Read()
{
    scanf("%d%d%d",&N,&M,&K);
    if(N % 2 == 1 && M % 2 == 0)
        swap(N,M);
}

void parimpar()
{
    DP[0] = N*M/2;
    DP[2] = 2;
    DP[3] = N + M - 4;
    DP[4] = N*M - DP[0] - DP[1] - DP[2] - DP[3];
    int crt = 0;
    for(int i = 0; i <= 4; ++i)
    {
        if(DP[i] > K)
        {
            crt += K * i;
            K -= K;
        }
        else
        {
            crt += DP[i]*i;
            K -= DP[i];
        }
        if(K == 0)
            break;
    }
    best = crt;
}

void parpar()
{
    DP[0] = N*M/2;
    DP[2] = 2;
    DP[3] = N+M-4;
    DP[4] = N*M - DP[0] - DP[1] - DP[2] - DP[3];
    int crt = 0;
    for(int i = 0; i <= 4; ++i)
    {
        if(DP[i] > K)
        {
            crt += K * i;
            K -= K;
        }
        else
        {
            crt += DP[i]*i;
            K -= DP[i];
        }
        if(K == 0)
            break;
    }
    best = crt;
}

void imparimpar()
{
    DP[0] = N*M/2 + 1;
    DP[3] = N+M-2;
    DP[4] = N*M - DP[0] - DP[3];
    int crt = 0;
    int savedK = K;
    for(int i = 0; i <= 4; ++i)
    {
        if(DP[i] > K)
        {
            crt += K * i;
            K -= K;
        }
        else
        {
            crt += DP[i]*i;
            K -= DP[i];
        }
        if(K == 0)
            break;
    }
    best = min(best,crt);
    DP[0] = N*M/2;
    DP[2] = 4;
    DP[3] = N+M-6;
    DP[4] = N*M - DP[0] - DP[2] - DP[3];
    crt = 0;
    K = savedK;
    for(int i = 0; i <= 4; ++i)
    {
        if(DP[i] > K)
        {
            crt += K * i;
            K -= K;
        }
        else
        {
            crt += DP[i]*i;
            K -= DP[i];
        }
        if(K == 0)
            break;
    }
    best = min(best,crt);

}

void unupar()
{
    DP[0] = N*M/2;
    DP[1] = 1;
    DP[2] = N*M - DP[0] - DP[1];
    int crt = 0;
    for(int i = 0; i <= 4; ++i)
    {
        if(DP[i] > K)
        {
            crt += K * i;
            K -= K;
        }
        else
        {
            crt += DP[i]*i;
            K -= DP[i];
        }
        if(K == 0)
            break;
    }
    best = crt;
}

void unuimpar()
{
    DP[0] = N*M/2 + 1;
    DP[2] = N*M - DP[0];
    int savedK = K;
    int crt = 0;
    for(int i = 0; i <= 4; ++i)
    {
        if(DP[i] > K)
        {
            crt += K * i;
            K -= K;
        }
        else
        {
            crt += DP[i]*i;
            K -= DP[i];
        }
        if(K == 0)
            break;
    }
    best=min(best,crt);
    K = savedK;
    crt = 0;
    DP[0] = N*M/2;
    DP[1] = 1;
    DP[2] = N*M - DP[0] - DP[1];
    for(int i = 0; i <= 4; ++i)
    {
        if(DP[i] > K)
        {
            crt += K * i;
            K -= K;
        }
        else
        {
            crt += DP[i]*i;
            K -= DP[i];
        }
        if(K == 0)
            break;
    }
    best = min(best,crt);
}

void Solve()
{
    if(N%2 == 0 && M%2 == 1 && M != 1)
    {
        parimpar();
        return;
    }
    if(N%2 == 0 && M%2 == 0)
    {
        parpar();
        return;
    }
    if(N%2 == 1 && M%2 == 1 && N!= 1 && M != 1)
    {
        imparimpar();
        return;
    }
    if(M == 1)
        swap(N,M);
    if(M % 2 == 0)
    {
        unupar();
        return;
    }
    if(M % 2 == 1 && M != 1)
    {
        unuimpar();
        return;
    }
    if(N == 1 && M == 1)
    {
        best = 0;
        return;
    }
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

    int tst;
    scanf("%d",&tst);
    for(int i = 1; i <= tst; ++i)
    {
        best = 99999999;
        memset(DP,0,sizeof(DP));
        Read();
        Solve();
        printf("Case #%d: %d\n",i,best);
    }

    return 0;
}
