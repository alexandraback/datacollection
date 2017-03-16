#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> mushrooms;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        mushrooms.push_back(value);
    }
    int ans = 0, mx = 0;
    for (int i = 1; i < n; i++) {
        if (mushrooms[i] < mushrooms[i - 1]) {
            ans += mushrooms[i - 1] - mushrooms[i];
            mx = max(mx, mushrooms[i - 1] - mushrooms[i]);
        }
    }
    printf("%d ", ans);
    ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        int value = mushrooms[i];
        if (value <= mx) {
            ans += value;
        }
        else {
            ans += mx;
        }
    }
    printf("%d\n", ans);
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