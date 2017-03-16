#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 16;
int r, c, t, n, vis[N][N];
int d[2][2] = {0, -1, -1, 0};
int ans;

void dfs(int x, int y, int sum, int n) {
    if (n == 0) {
        ans = min(ans, sum);
        return;
    }
    if (sum > ans) return;
    if (x == r) return;
    if (y == c) {
        dfs(x + 1, 0, sum, n);
        return;
    }
    int sb = sum;
    for (int i = 0; i < 2; i++) {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        if (dx >= 0 && dx < r && dy >= 0 && dy < c && vis[dx][dy]) sb += 1;
    }
    dfs(x, y + 1, sum, n);
    vis[x][y] = 1;
    dfs(x, y + 1, sb, n - 1);
    vis[x][y] = 0;
}

int main() {
    scanf("%d", &t);
    int cas = 0;
    while (t--) {
        ans = 100000000;
        scanf("%d%d%d", &r, &c, &n);
        dfs(0, 0, 0, n);
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
