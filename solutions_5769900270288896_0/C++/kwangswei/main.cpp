#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calc(vector<vector<int>>& board) {
    int unhappy = 0;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size() - 1; ++j) {
            if (board[i][j] == 0)
                continue;

            if (board[i][j+1] == 1)
                unhappy++;
        }

        if (i < board.size() - 1) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 0)
                    continue;

                if (board[i+1][j] == 1)
                    unhappy++;
            }
        }
    }

    return unhappy;
}

int solve(vector<vector<int>>& board, int N, int r, int c) {
    if (r == board.size()) {
        if (N == 0)
            return calc(board);
        else
            return 987654321;
    }
    if (c == board[r].size())
        return solve(board, N, r+1, 0);

    if (N == 0)
        return calc(board);


    board[r][c] = 1;
    int result = solve(board, N-1, r, c+1);
    board[r][c] = 0;
    result = min(result, solve(board, N, r, c+1));

    return result;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int R, C, N;
        cin >> R >> C >> N;

        auto board = vector<vector<int>>(R, vector<int>(C, 0));
        printf("Case #%d: %d\n", i, solve(board, N, 0, 0));
    }

    return 0;
}
