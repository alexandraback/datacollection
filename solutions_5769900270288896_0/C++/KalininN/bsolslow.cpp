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

int f[20][20];

int main()
{
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        printf("Case #%d: ", T);
        
        int r, c, n;
        scanf("%d%d%d", &r, &c, &n);
        int km = 1 << (r * c);
        int answer = 4 * n;
        for (int i = 0; i <= r + 1; i++)
        {
            for (int j = 0; j <= c + 1; j++) f[i][j] = 0;
        }
        for (int mask = 0; mask < km; mask++) if (__builtin_popcount(mask) == n)
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++) f[i + 1][j + 1] = ((mask >> (i * c + j)) & 1);
            }
            int ans = 0;
            for (int i = 1; i <= r; i++)
            {
                for (int j = 1; j <= c; j++) if (f[i][j])
                {
                    ans += f[i - 1][j] + f[i][j - 1] + f[i][j + 1] + f[i + 1][j];
                }
            }
//             cout << mask << ' ' << ans << endl;
            answer = min(answer, ans / 2);
        }
        printf("%d\n", answer);
        
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
