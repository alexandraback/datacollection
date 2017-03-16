#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 33, inf = 1111111111;

int t, n, a[max_n];

bool check() {
    int mx = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, a[i]);
        sum += a[i];
    }
    if (mx * 2 > sum) {
        return false;
    }
    return true;
}

pair<int, int> get_mx() {
    pair<int, int> mx = make_pair(0, inf);
    for (int i = 0; i < n; ++i) {
        mx = max(mx, make_pair(a[i], i));
    }
    return mx;
}

int main() {
    freopen("A-large.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &t);
    for (int test = 1; test <= t; ++test) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        string ans = "";
        while (true) {
            pair<int, int> mx = get_mx();
            if (mx.second == inf) {
                break;
            }
            ans += mx.second + 'A';
            --a[mx.second];
            if (check()) {
                ans += ' ';
            } else {
                mx = get_mx();
                ans += mx.second + 'A';
                --a[mx.second];
                ans += ' ';
            }
        }
        printf("Case #%d: %s\n", test, ans.c_str());
    }
    return 0;
}
