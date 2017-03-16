#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    vector<long long> x, y;
    for (int i = 0; i < n; i++) {
        int thisX, thisY;
        cin >> thisX >> thisY;
        x.push_back(thisX);
        y.push_back(thisY);
    }
    vector<int> ans;
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        ans[i] = n - 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long a = y[i] - y[j];
            long long b = x[j] - x[i];
            long long c = -a * x[i] - b * y[i];
            int s1 = 0, s2 = 0;
            for (int u = 0; u < n; u++) {
                long long value = a * x[u] + b * y[u] + c;
                if (value > 0) {
                    s1++;
                }
                else if (value < 0) {
                    s2++;
                }
            }
            ans[i] = min(ans[i], min(s1, s2));
            ans[j] = min(ans[j], min(s1, s2));
        }
    }
    printf("\n");
    for (int value : ans) {
        printf("%d\n", value);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    for (int test = 1; test <= tc; test++) {
        printf("Case #%d: ", test);
        solve();
    }
    return 0;
}