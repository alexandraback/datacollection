#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <stack>
#include <assert.h>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <queue>

using namespace std;

int T;
int n, m, x;

int getCnt(int x) {
    int cnt = 0;
    while (x) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}

bool a[18][18];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> m >> x;
        int ans = 1e9;
        for (int k = 0; k < (1 << (n * m)); ++k) {
            int cnt = getCnt(k);
            if (cnt != x)
                continue;
            for (int i = 0; i <= n + 1; ++i)
                for (int j = 0; j <= m + 1; ++j)
                    a[i][j] = false;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    if (k & (1 << ((i - 1) * m + j - 1)))
                        a[i][j] = true;
            int col = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    if (a[i][j]) {
                        col += (a[i + 1][j]);
                        col += (a[i][j + 1]);
                    }
            ans = min(ans, col);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}