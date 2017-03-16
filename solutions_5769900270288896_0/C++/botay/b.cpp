#include <iostream>
#include <vector>

using namespace std;

int bitcnt(int value)
{
    int res = 0;
    while (value)
    {
        if (value & 1)
            res++;
        value >>= 1;
    }
    return res;
}

int simpleSolve(int R, int C, int N)
{
    int ans = 4*R*C;
    int W = R*C;
    for (int mask = 0; mask < (1 << W); ++mask)
    {
        if (bitcnt(mask) != N)
            continue;

        bool f[R][C];
        for (int i = 0; i < W; ++i)
        {
            f[i / C][i % C] = ((mask >> i) & 1);
        }
        int unhap = 0;
        for (int x = 0; x < R; ++x)
        {
            for (int y = 0; y < C; ++y)
                if (f[x][y])
                {
                    if (x + 1 < R && f[x + 1][y])
                    {
                        ++unhap;
                        //cerr << " " << mask << " | " << x << " " << y << endl;
                    }
                    if (y + 1 < C && f[x][y + 1])
                    {
                        ++unhap;
                        //cerr << " " << mask << " - " << x << " " << y << endl;
                    }
                }
        }
        if (unhap < ans)
            ans = unhap;
    }
    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int testId = 1; testId <= T; ++testId)
    {
        int R, C, N;
        cin >> R >> C >> N;
        cout << "Case #" << testId << ": " << simpleSolve(R, C, N) << endl;
    }

    return 0;
}
