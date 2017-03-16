#include <cstdio>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

inline int bit(int x, int i)
{
    return (x >> i) & 1;
}

int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};

void solve(int cs)
{
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    int gans = 10000, gmsk = -1;
    for (int msk = 0; msk < (1 << (r * c)); msk++)
    {
        if (__builtin_popcount(msk) != n)
            continue;
        int ans = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                if (!bit(msk, i * c + j))
                    continue;
                for (int v = 0; v < 4; v++)
                {
                    int ti = i + vy[v];
                    int tj = j + vx[v];
                    if (ti < 0 || ti >= r || tj < 0 || tj >= c)
                        continue;
                    if (!bit(msk, ti * c + tj))
                        continue;
                    ans++;
                }
            }
        ans /= 2;
        if (gans > ans)
            gans = ans, gmsk = msk;
    }
    printf("Case #%d: %d\n", cs, gans);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            eprintf("%c", ".*"[bit(gmsk, i * c + j)]);
        eprintf("\n");
    }

}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i + 1);
}
