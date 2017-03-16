#include <bits/stdc++.h>

using namespace std;

void Solve (int test_num) {
    long long b, n;
    cin >> b >> n;
    vector<int> m(b);
    for (auto& i : m) {
        scanf("%d", &i);
    }
    if (n <= b) {
        printf("Case #%d: %lld\n", test_num, n);
        return;
    }
    long long l = 0, r = m[0] * n;
    while (r - l > 1) {
        long long t = (r + l) >> 1;
        long long hc = 0;
        for (auto i : m) {
            hc += t / i;
            ++hc;
        }
        if (hc < n) {
            l = t;
        } else {
            r = t;
        }
    }
    long long hc = 0;
    for (auto i : m) {
        hc += l / i;
        ++hc;
    }
    for (int i = 0, j = n - hc;; ++i) {
        if (r % m[i] != 0) continue;
        --j;
        if (j == 0) {
            printf("Case #%d: %d\n", test_num, i + 1);
            return;
        } 
    }
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        Solve(i + 1);
    }
}
