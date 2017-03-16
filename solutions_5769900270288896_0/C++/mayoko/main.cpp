#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;

int solve(int R, int C, int N) {
    int n = R*C;
    int ans = 100000;
    for (int s = 0; s < 1<<n; s++) {
        int cnt = __builtin_popcount(s);
        if (cnt != N) continue;
        bool board[R][C];
        memset(board, 0, sizeof(board));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int tmp = i*C+j;
                if ((s>>tmp)&1) {
                    board[i][j] = true;
                }
            }
        }
        int score = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!board[i][j]) continue;
                for (int k = 0; k < 4; k++) {
                    int ny = i+dy[k];
                    int nx = j+dx[k];
                    if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                    if (board[ny][nx]) score++;
                }
            }
        }
        ans = min(ans, score/2);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int R, C, N;
        cin >> R >> C >> N;
        printf("Case #%d: %d\n", t, solve(R, C, N));
    }
    return 0;
}
