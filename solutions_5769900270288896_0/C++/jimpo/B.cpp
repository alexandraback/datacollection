#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <memory>

typedef long long ll;

using namespace std;

int population(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int occupied(int R, int C, int n, int i, int j) {
    if (i < 0 || i >= R || j < 0 || j >= C) {
        return 0;
    }
    return (n >> (i * C + j)) & 1;
}

int solve(int R, int C, int N) {
    int min = N * 4;
    for (int n = 0; n < (1<<(R*C)); n++) {
        if (population(n) == N) {
            int score = 0;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (occupied(R, C, n, i, j)) {
                        score += occupied(R, C, n, i - 1, j);
                        score += occupied(R, C, n, i + 1, j);
                        score += occupied(R, C, n, i, j - 1);
                        score += occupied(R, C, n, i, j + 1);
                    }
                }
            }
            score /= 2;
            if (score < min) {
                min = score;
            }
        }
    }
    return min;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int R, C, N;
        cin >> R >> C >> N;
        cout << "Case #" << i + 1 << ": " << solve(R, C, N) << endl;
    }
}
