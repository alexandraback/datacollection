#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

const int maxn = 40005;
const int inf = 1e9;

int ans[2][maxn][2];
bool bad[maxn];
int r, c;

void clear(int len)
{
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            for (int t = 0; t < 2; t++) ans[i][j][t] = inf;
        }
    }
}

void run(int len)
{
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            ans[i & 1][j][0] = min(ans[(i & 1) ^ 1][j][0], ans[(i & 1) ^ 1][j][1]);
            if (j > 0) ans[i & 1][j][1] = min(ans[(i & 1) ^ 1][j - 1][0], ans[(i & 1) ^ 1][j - 1][1] + 1) + bad[i];
        }
    }
}

int calc(int n, int odd)
{
    int len = (r + c - 2) * 2;
    assert(n <= len);
    for (int i = 0; i <= len; i++) bad[i] = 0;
    for (int i = 1; i < r - 1; i++) bad[i] = (0 + i) % 2 != odd;
    for (int i = 1; i < c - 1; i++) bad[(r - 1) + i] = (i + r - 1) % 2 != odd;
    for (int i = 1; i < r - 1; i++) bad[(r + c - 2) + i] = (c - 1 + r - 1 - i) % 2 != odd;
    for (int i = 1; i < c - 1; i++) bad[(2 * r + c - 3) + i] = (c - 1 - i + 0) % 2 != odd;
//     for (int i = 0; i < len; i++) cout << bad[i];
//     cout << endl;
    clear(len + 1);
    ans[0][0][0] = 0;
    run(len + 1);
    int curans1 = ans[len & 1][n][0];
    clear(len + 1);
    ans[0][1][1] = 0;
    run(len + 1);
    int curans2 = ans[len & 1][n + 1][1];
//     cout << "calc " << n << ' ' << odd << ' ' << curans1 << ' ' << curans2 << endl;
    return min(curans1, curans2);
}

#define popcount __builtin_popcount

int ans2[2][maxn][4];
int stupid(int r, int c, int n)
{
    assert(c == 2);
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int m1 = 0; m1 < 4; m1++)
            {
                ans2[i][j][m1] = inf;
            }
        }
    }
    ans2[0][0][0] = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int m1 = 0; m1 < 4; m1++) if (j >= popcount(m1))
            {
                ans2[i & 1][j][m1] = inf;
                int was = j - popcount(m1);
                for (int m2 = 0; m2 < 4; m2++)
                {
                    ans2[i & 1][j][m1] = min(ans2[i & 1][j][m1], ans2[(i - 1) & 1][was][m2] + popcount(m1 & m2) + (popcount(m1) > 1));
                }
            }
        }
    }
    int answer = 4 * n;
    for (int m = 0; m < 4; m++) answer = min(answer, ans2[r & 1][n][m]);
    return answer;
}

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d:", T);
        
        int n;
        scanf("%d%d%d", &r, &c, &n);
        
        if (n <= (r * c + 1) / 2)
        {
            printf(" %d\n", 0);
            continue;
        }
        if (r < c) swap(r, c);
        if (c == 1)
        {
            printf(" %d\n", 2 * n - 2 - (r - 1));
            continue;
        }
        if (c == 2)
        {
            printf(" %d\n", stupid(r, c, n));
            continue;
        }
        if (n >= (r + c - 2) * 2 + (r - 2) * (c - 2) / 2)
        {
            printf(" %d\n", 4 * n - 2 * (r + c) - (r - 1) * c - r * (c - 1));
            continue;
        }
        int spin = (r - 2) * (c - 2);
        printf(" %d\n", min(calc(n - (spin + 1) / 2, 0), calc(n - spin / 2, 1)));
        
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
