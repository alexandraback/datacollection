#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 222222;

int T, n, m, a[N];

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        long long st = 0;
        long long ed = 2LL * (long long) 1e14;
        while (st < ed) {
            long long mid = (st + ed) / 2;
            long long tot = 0;
            for (int i = 0; i < n; i++) {
                tot += mid / a[i] + 1;
            }
            if (tot >= m) {
                ed = mid;
            } else {
                st = mid + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            m -= (st - 1) / a[i] + 1;
        }
        vector <int> idx;
        for (int i = 0; i < n; i++) {
            if (st % a[i] == 0) {
                idx.push_back(i + 1);
            }
        }
        sort(idx.begin(), idx.end());
        printf("Case #%d: %d\n", t, idx[m - 1]);
    }

    return 0;

}
