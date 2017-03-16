#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

int T;
int R, C, N;
int M;

int dp[1<<16];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    scanf("%d", &T);
    REP(tc, T)
    {
        scanf("%d %d %d", &R, &C, &N);
        M = R*C;

        int minNoisy = 999999999;

        REP(mask, 1<<M)
        {
            if (__builtin_popcount(mask) != N)
                continue;

            int noisy = 0;

            REP(i, M) if (mask & (1<<i))
            {
                int x = i/C, y = i%C;

                REP(k, 4)
                {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                        continue;

                    int ni = nx*C + ny;

                    if (mask & (1<<ni))
                        noisy++;
                }
            }

            minNoisy = min(minNoisy, noisy/2);
        }

        printf("Case #%d: %d\n", tc+1, minNoisy);
    }
}
