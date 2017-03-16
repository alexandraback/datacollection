#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

// f[i][j][k] denotes 前i行，状态为j，总房间数为k的最小代价
int f[20][200000][20];
int h[200000];
int g[200000];
int r, c, n;

int count(int x)
{
    int ret = 0;
    for (int i = 0; i < 32; i++) {
        ret += (x >> i) & 1;
    }
    return ret;
}

void work()
{
    scanf("%d%d%d", &r, &c, &n);
    if (n <= 1) {
        cout << 0 << endl;
        return;
    }
    if (r < c) {
        swap(r, c);
    }
    memset(f, -1, sizeof f);
    memset(g, 0, sizeof g);
    memset(h, 0, sizeof h);
    for (int i = 0; i < (1 << c); i++) {
        for (int j = 0; j < c - 1; j++) {
            if (((i >> j) & 1) & ((i >> (j + 1)) & 1)) {
                g[i]++;
            }
            if ((i >> j) & 1) {
                h[i]++;
            }
        }
        h[i] += i >> (c - 1);
        f[0][i][h[i]] = g[i];// + h[i];
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < (1 << c); j++) {
            for (int k = 0; k <= (i + 1) * c; k++) {
                if (f[i][j][k] == -1 || k < h[i]) continue;
                for (int l = 0; l < (1 << c); l++) {
                    if (k + h[l] > n) {
                        continue;
                    }
                    if (f[i + 1][l][k + h[l]] == -1) {
                        f[i + 1][l][k + h[l]] = f[i][j][k] + g[l] + count(l & j);
                    } else {
                        f[i + 1][l][k + h[l]] = min(f[i + 1][l][k + h[l]], f[i][j][k] + g[l] + count(l & j));
                    }
                }
            }
        }
    }
    int ans = ~0u>>1;
    for (int i = 0; i < (1 << c); i++) {
        if (f[r - 1][i][n] != -1)
            ans = min(ans, f[r - 1][i][n]);
    }
    cout << ans << endl;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}