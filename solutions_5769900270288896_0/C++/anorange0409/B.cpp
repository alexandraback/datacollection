#include <iostream>
#include <cstdio>
using namespace std;

bool  mark[17][17];
int n,m,ans,K;
void next(int x, int y, int &xx, int &yy) {
    if (y < m) {
        xx = x; yy = y + 1;
    } else {
        xx = x + 1; yy = 1;
    }
}

void check() {
    int re = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        if (j > 1 && mark[i][j]&&mark[i][j-1])
            re++;
        if (i > 1 && mark[i][j]&&mark[i-1][j])
            re++;
    }
    if (re < ans)
        ans = re;
}

void dfs(int x, int y, int dep) {
    if (dep > K) {check();} else{
        if (x > n) return;
        int xx, yy;
        next(x,y,xx,yy);

        mark[x][y] = true;
        dfs(xx,yy,dep+1);
        mark[x][y] = false;
        dfs(xx,yy,dep);
    }
}
int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);

    int T; cin >> T;
    for (int o = 1; o <= T; o++) {

        cin >> n >> m >> K;
        ans = 10000;
        dfs(1,1,1);
        printf("Case #%d: %d\n",o,ans);
    }
}
