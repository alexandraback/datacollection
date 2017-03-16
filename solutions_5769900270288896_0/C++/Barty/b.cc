#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool vst[20][20];
int r, c, n, res;
int gao() {
    int cnt = 0;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j < c; ++j)
            if (vst[i][j] && vst[i][j + 1]) ++cnt;
    for (int i = 1; i < r; ++i)
        for (int j = 1; j <= c; ++j)
            if (vst[i][j] && vst[i + 1][j]) ++cnt;
    return cnt;
}
void dfs(int x, int y, int cnt) {
    if (cnt == n) {
        res = min(res, gao());
        return;
    }
    if (x == r + 1) {
        return;
    }
    int nx = x, ny = y + 1;
    if (ny == c + 1) {
        nx++;
        ny = 1;
    }
    dfs(nx, ny, cnt);
    vst[x][y] = 1;
    dfs(nx, ny, cnt + 1);
    vst[x][y] = 0;
}
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d%d", &r, &c, &n);
        res = 1000000000;
        dfs(1, 1, 0);
        printf("Case #%d: %d\n", ca, res);
    }
    return 0;
}
