# include <stdio.h>
# include <string.h>
# include <iostream>

typedef long long int lli;
using namespace std;

# define testin freopen("B-small-attempt0.in", "r", stdin)
# define testout freopen("out.txt", "w", stdout)

const int N = 20;
int R, C;
const int INF = 999999;

int cb(int x) {
    int re = 0;
    while (x) {
        x&=(x-1);
        ++re;
    }
    return re;
}

bool b[N][N];

int ca(int x) {
    for (int i = 0; i < R*C; ++i) {
        int t = (x>>i)&0x1;
        b[i/C][i%C] = t;
    }
    int ret = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (j+1<C&&b[i][j]&&b[i][j+1]) ++ret;
            if (i+1<R&&b[i][j]&&b[i+1][j]) ++ret;
        }
    }
    return ret;
}

int n;

int main()
{
    testin;
    testout;
    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        printf("Case #%d: ", ica);
        scanf("%d%d%d", &R, &C, &n);
        int m = R*C;
        int ans = INF;
        for (int i = 0; i < (1<<m); ++i) {
            int x = cb(i);
            if (x == n) {
                int t = ca(i);
                ans = min(ans, t);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
