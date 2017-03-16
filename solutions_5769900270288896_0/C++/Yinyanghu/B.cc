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

int main() {
    int T;
    scanf("%d", &T);    
    for (int test = 1; test <= T; ++ test) {
        scanf("%d %d %d", &R, &C, &N);
        res = 1000000;
        dfs(0, 0, 0);
        printf("Case #%d: %d\n", test, res);
    }
    return 0;
}
