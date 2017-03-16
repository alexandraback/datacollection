#include <cassert>
#include <cstdio>
#include <climits>
#include <utility>
#include <vector>
#include <algorithm>

const int DELTA_X[] = {-1, 0, 0, 1};
const int DELTA_Y[] = {0, -1, 1, 0};

int solve(int n, int m, int k)
{
    int result = INT_MAX;
    for (int p = 0; p < 2; ++ p) {
        int free = 0;
        std::vector <int> costs;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if ((i + j & 1) == p) {
                    int cost = 0;
                    for (int k = 0; k < 4; ++ k) {
                        int x = i + DELTA_X[k];
                        int y = j + DELTA_Y[k];
                        if (0 <= x && x < n && 0 <= y && y < m) {
                            cost ++;
                        }
                    }
                    costs.push_back(cost);
                } else {
                    free ++;
                }
            }
        }
        std::sort(costs.begin(), costs.end());
        int need = 0;
        if (k > free) {
            for (int i = 0; i < k - free; ++ i) {
                need += costs[i];
            }
        }
        result = std::min(result, need);
    }
    return result;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        printf("Case #%d: %d\n", t, solve(n, m, k));
    }
    // for (int n = 1; n <= 25; ++ n) {
    //     for (int m = n; n * m <= 25; ++ m) {
    //         for (int k = 0; k <= n * m; ++ k) {
    //             std::pair <int, int> result(INT_MAX, 0);
    //             for (int mask = 0; mask < 1 << n * m; ++ mask) {
    //                 if (__builtin_popcount(mask) == k) {
    //                     int cost = 0;
    //                     for (int i = 0; i < n; ++ i) {
    //                         for (int j = 0; j < m; ++ j) {
    //                             if (mask >> i * m + j & 1) {
    //                                 for (int k = 0; k < 2; ++ k) {
    //                                     int x = i + (k == 0);
    //                                     int y = j + (k == 1);
    //                                     if (x < n && y < m) {
    //                                         cost += mask >> x * m + y & 1;
    //                                     }
    //                                 }
    //                             }
    //                         }
    //                     }
    //                     result = std::min(result, {cost, mask});
    //                 }
    //             }
    //             printf("%d %d %d %d %d\n", n, m, k, result.first, solve(n, m, k));
    //             for (int i = 0; i < n; ++ i) {
    //                 for (int j = 0; j < m; ++ j) {
    //                     printf("%d", result.second >> i * n + j & 1);
    //                 }
    //                 puts("");
    //             }
    //             assert(solve(n, m, k) == result.first);
    //         }
    //     }
    // }
}
