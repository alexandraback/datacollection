#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, B, m[10000];

int main() {
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d %d", &B, &N);
        for (int i = 0; i < B; ++i)
            scanf("%d", &m[i]);
        long long l = 0, r = (long long)N * 100007, mid, temp;
        while (l < r - 1) {
            mid = (l + r) / 2;
            temp = 0;
            for (int i = 0; i < B; ++i)
                temp += (mid + m[i] - 1) / (long long)m[i];
            if (temp >= N)
                r = mid;
            else
                l = mid;
        }
        for (int i = 0; i < B; ++i)
            N -= (l + m[i] - 1) / (long long)m[i];
        int i;
        for (i = 0; i < B; ++i)
            if (l % m[i] == 0) {
                if (N == 1)
                    break;
                --N;
            }
        printf("Case #%d: %d\n", Case, i + 1);
    }
    return 0;
}
