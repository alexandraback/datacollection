#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
int r, c;

int ans;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int n, int cnt) {
    if (n == 0) {
        ans = min(ans, cnt);
        return;
    }

    if (y > c) x += 1, y = 1;
    if (x > r) return ;

    int gg = arr[x-1][y] + arr[x][y-1];

    arr[x][y] = 1;
    dfs(x, y+1, n-1, cnt + gg);
    arr[x][y] = 0;

    dfs(x, y+1, n, cnt);
}

int jizz() {
    int n;
    scanf("%d%d%d", &r, &c, &n);

    ans = 1e9;

    dfs(1, 1, n, 0);

    return ans;
}

int main() {
    int T; scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %d\n", t, jizz());
    }

    return 0;
}