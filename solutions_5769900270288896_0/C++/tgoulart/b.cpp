#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

char board[16][16];
int R, C;
int best;

int currentUnhappiness() {
    int ans = 0;
    for (int i=0; i < R; ++i) {
        for (int j=0; j < C; ++j) {
            if (board[i][j]) {
                if (j > 0) {
                    ans += board[i][j-1];
                }
                if (i > 0) {
                    ans += board[i-1][j];
                }
            }
        }
    }
    return ans;
}

void dfs(int index, int left, int available) {
    if (available - index < left) {
        return;
    }
//    printf("%d %d %d\n", index, left, available);
    if (!left) {
        best = min(best, currentUnhappiness());
        return;
    }
    int row = index / C;
    int col = index % C;
    dfs(index + 1, left, available);
    board[row][col] = 1;
    dfs(index + 1, left - 1, available);
    board[row][col] = 0;
}

void solve(int testNo) {
    cout << "Case #" << testNo << ": ";

    int N;
    cin >> R >> C >> N;
    memset(board, 0, sizeof(board));

    best = 1000000;
    dfs(0, N, R * C);

    cout << best << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
