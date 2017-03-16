#include <bits/stdc++.h>
using namespace std;

int unhappiness(int R, int C, int mask)
{
    vector<vector<bool>> building;
    building.resize(R);
    for (int r = 0; r < R; r++) building[r].resize(C);

    for (int i = 0; i < R * C; i++)
    {
        building[i/C][i%C] = mask % 2;
        mask >>= 1;
    }

    int count = 0;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C - 1; c++)
            if (building[r][c] && building[r][c + 1]) count++;
    for (int c = 0; c < C; c++)
        for (int r = 0; r < R - 1; r++)
            if (building[r][c] && building[r + 1][c]) count++;
    return count;
}

int solve(int R, int C, int N)
{
    int ans = 4*R*C;
    for (int mask = 0; mask < (1 << R*C); mask++)
    {
        if (__builtin_popcount(mask) != N) continue;
        ans = min(ans, unhappiness(R, C, mask));
    }
    return ans;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int R, C, N; cin >> R >> C >> N;
        printf("Case #%d: %d\n", t, solve(R, C, N));
    }
    return 0;
}
