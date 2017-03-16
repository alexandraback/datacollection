#include <bits/stdc++.h>
using namespace std;

int N, R, C;
bool visit[20][20];

void print() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            putchar(visit[i][j] ? '*' : '.');
        }
        putchar('\n');
    }
    putchar('\n');
}

int countWall() {
    int ret = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (j && visit[i][j] && visit[i][j - 1]) {
                ++ret;
            }
            if (i && visit[i][j] && visit[i - 1][j]) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &R, &C, &N);
        int ans = 0x7fffffff;
        for (int i = 0; i < (1 << (R * C)) && ans; ++i) {
            memset(visit, false, sizeof(visit));
            int num = 0;
            for (int j = 0; (1 << j) <= i && ans; ++j) {
                if (i & (1 << j)) {
                    int x = j / C;
                    int y = j % C;
                    visit[x][y] = true;
                    ++num;
                }
            }
            if (num == N) {
                ans = min(ans, countWall());
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
