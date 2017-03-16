#include <bits/stdc++.h>
#define LL long long int
#define ULL unsigned long long int
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, f, n) for(int i = (f); i <= (n); ++i)
using namespace std;

const int M = 20;
int t[M][M];

int solve(int r, int c, int n)
{
    int wynik = 100000;
    for(int i = 0; i < (1<<(r*c)); ++i)
    {
        unsigned int tmp = i;
        int k = 0;
        for(int x = 0; x < c; ++x)
        for(int y = 0; y < r; ++y)
        {
            if((tmp&1) == 0)
                t[x][y] = 0;
            else
            {
                t[x][y] = 1;
                ++k;
            }
            tmp >>= 1;
        }
        if(k != n) continue;
        int tw = 0;
        REP(x, c)
        REP(y, r)
        {
           // if(x > 0) tw += t[x-1][y];
            //if(y > 0) tw += t[x][y-1];
            if(!t[x][y]) continue;
            if(x < c-1) tw += t[x+1][y];
            if(y < r-1) tw += t[x][y+1];
        }
        wynik = min(wynik, tw);
    }
    return wynik;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i)
    {
        int R, C, N;
        scanf("%d%d%d", &R, &C, &N);
        printf("Case #%d: %d\n", i, solve(R, C, N));
    }
    return 0;
}

