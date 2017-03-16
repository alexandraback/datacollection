#include <cstdio>
#include <algorithm>

using namespace std;

int r, c, n;

int f(int state, int row, int col, int left) {
    if (left == 0) {
        return 0;
    }
    if (row >= r) {
        return 1 << 30;
    }

    int cur = row * c + col;
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol >= c) {
        ++nextRow;
        nextCol = 0;
    }

    // add
    int score = 0;
    if (col > 0) {
        int left = row * c + col - 1;
        if (state & (1 << left)) {
            ++score;
        }
    }
    if (row > 0) {
        int up = (row - 1) * c + col;
        if (state & (1 << up)) {
            ++score;
        }
    }
    score += f(state | (1 << cur), nextRow, nextCol, left - 1);

    // don't add
    int score2 = f(state, nextRow, nextCol, left);

    return min(score, score2);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d %d %d", &r, &c, &n);

        printf("Case #%d: %d\n", t, f(0, 0, 0, n));
    }
}