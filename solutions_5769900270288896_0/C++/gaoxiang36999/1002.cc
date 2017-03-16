#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 50
using namespace std;
int malt[MAXN][MAXN];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int num;
int ans;
bool isok(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}
void solve() {
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(malt[i][j]) {
                for(int k = 0; k < 4; k++) {
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if(isok(nx, ny) && malt[nx][ny]) res++;
                }
            }
        }
    }
    res /= 2;
    ans = min(ans, res);
}
void dfs(int x, int y) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) sum += malt[i][j];
    }
    if(sum >= num) {
        solve();
        return;
    }
    if(y >= m) {
        x++;
        y = 0;
    }
    if(x >= n) return;
    malt[x][y] = 1;
    dfs(x, y + 1);
    malt[x][y] = 0;
    dfs(x, y + 1);
}
int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("outB.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        ans = 100000000;
        scanf("%d%d%d", &n, &m, &num);
        dfs(0, 0);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
