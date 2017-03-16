#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    freopen("B-small.in", "r", stdin);
    freopen("B-small.out", "w", stdout);

    int tests, test = 1;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        int r, c, n;
        scanf("%d%d%d", &r, &c, &n);
        int total = r * c;
        int answer = r * c * 4;
        for (int mask = 0; mask < 1 << total; ++ mask) {
            if (__builtin_popcount(mask) != n) {
                continue;
            }
            int cur = 0;
            for (int i = 0; i < r; ++ i) {
                for (int j = 0; j < c; ++ j) {
                    if (mask >> (i * c + j) & 1) {
                        for (int k = 0; k < 4; ++ k) {
                            int x = i + dx[k], y = j + dy[k];
                            if (x >= 0 && y >= 0 && x < r && y < c) {
                                cur += mask >> (x * c + y) & 1;
                            }
                        }
                    }
                }
            }
            answer = min(answer, cur / 2);
        }
        printf("Case #%d: %d\n", test, answer);
    }
    return 0;
}
