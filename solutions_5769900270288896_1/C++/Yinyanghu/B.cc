#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool flag[16][16];

int res;

int R, C, N;

void dfs(int depth, int K, int total) {
    if (depth == R * C) {
        if (K == N && total < res) res = total;
        return;
    }
    int x = depth / C;
    int y = depth % C;
    flag[x][y] = true;
    dfs(depth + 1, K, total);
    flag[x][y] = false;
    int next = 0;
    if (x > 0 && !flag[x - 1][y]) ++ next;
    if (y > 0 && !flag[x][y - 1]) ++ next;
    dfs(depth + 1, K + 1, total + next);
}

int oddA(int R, int C, int N) {
    int ret = 0;
    int RC = R * C;
    int zero = (RC >> 1) + 1;
    int three = ((R >> 1) + (C >> 1)) * 2;
    if (N <= zero) return 0;
    N -= zero;
    if (N <= three) return N * 3;
    N -= three;
    ret = ret + 3 * three;

    ret = ret + 4 * N;
    return ret;
}

int oddB(int R, int C, int N) {
    int ret = 0;
    int RC = R * C;
    int zero = RC >> 1;
    int two = 4;
    int three = ((R >> 1) + 1 + (C >> 1) + 1) * 2 - two * 2;
    if (N <= zero) return 0;
    N -= zero;
    if (N <= two) return N * 2;
    N -= two;
    ret = ret + 2 * two;
    if (N <= three) return ret + N * 3;
    N -= three;
    ret = ret + 3 * three;

    ret = ret + 4 * N;
    return ret;
}

int oddOneA(int K, int N) {
    int zero = (K >> 1) + 1;
    if (N <= zero) return 0;
    N -= zero;
    return N * 2;
}


int oddOneB(int K, int N) {
    int zero = K >> 1;
    if (N <= zero) return 0;
    N -= zero;
    int one = 2;
    if (N <= one) return N;
    N -= one;
    return one + 2 * N;
}

int one(int K, int N) {
    if (K == 1) return 0;
    if (K % 2 == 0) {
        int zero = K >> 1;
        if (N <= zero) return 0;
        N -= zero;
        if (N <= 1) return 1;
        -- N;
        return 1 + N * 2;
    }
    return min(oddOneA(K, N), oddOneB(K, N));
}

int solve(int R, int C, int N) {
    if (R == 1)
        return one(C, N);
    if (C == 1)
        return one(R, N);
    if ((R % 2 == 1) && (C % 2 == 1)) {
        return min(oddA(R, C, N), oddB(R, C, N));
    }
    int ret = 0;
    int RC = R * C;
    int zero = RC >> 1;
    int two = 2;
    int three = R + C - two * 2;
    if (N <= zero) return 0;
    N -= zero;
    if (N <= two) return N * 2;
    N -= two;
    ret = ret + 2 * two;
    if (N <= three) return ret + N * 3;
    N -= three;
    ret = ret + 3 * three;

    ret = ret + 4 * N;
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);    
    for (int test = 1; test <= T; ++ test) {
        scanf("%d %d %d", &R, &C, &N);
        int K = solve(R, C, N);
        printf("Case #%d: %d\n", test, K);
    }
    return 0;
}
