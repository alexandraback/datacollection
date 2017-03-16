#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int m[1010];

bool ok(long long totT, int b, int n) {
    long long has = 0;
    for (int i = 0; i < b; i ++) {
        has += (totT + m[i] - 1) / m[i];
    }
    return has < n;
}

set<pair<long long, int>> ss;

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas ++) {
        int b, n;
        scanf("%d%d", &b, &n);
        for (int i = 0; i < b; i ++) {
            scanf("%d", &m[i]);
        }
        int id = max_element(m, m + b) - m;
        long long L = 0, R = (long long)m[id] * n;
        while (L + 1 < R) {
            long long mid = (L + R) / 2;
            if (ok(mid, b, n)) {
                L = mid;
            } else {
                R = mid;
            }
        }
        long long totT;
        if (ok(R, b, n)) {
            totT = R;
        } else {
            totT = L;
        }
        int has = 0;
        ss.clear();
        for (int i = 0; i < b; i ++) {
            has += (totT + m[i] - 1) / m[i];
            ss.insert(make_pair(totT % m[i], i));
        }
        int res = 0;
        for (int i = has; i < n; i ++) {
            auto x = *ss.begin();
            ss.erase(x);
            ss.insert(make_pair(x.first + m[x.second], x.second));
            res = x.second;
        }
        printf("Case #%d: %d\n", cas, res + 1);
        fprintf(stderr, "Case #%d: %d\n", cas, res + 1);
    }
    return 0;
}