#include <bits/stdc++.h>

using namespace std;

void Solve (int test_num) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (auto& i : a) {
        scanf("%d", &i);
    }
    int ans[2];
    ans[0] = 0;
    int max_int = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            ans[0] += a[i] - a[i + 1];
        }
        max_int = max(max_int, a[i] - a[i + 1]);
    }
    ans[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans[1] += min(max_int, a[i]);
    }
    printf("Case #%d: %d %d\n", test_num, ans[0], ans[1]);
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        Solve(i + 1);
    }
}
