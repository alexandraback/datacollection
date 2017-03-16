#include <bits/stdc++.h>

int c[26];

void solve() {
    int n;
    scanf("%d", &n);
    std::vector<int> p(n);
    std::set<std::pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        s.emplace(-p[i], i);
    }
    int total = std::accumulate(p.begin(), p.end(), 0);
    while (s.begin()->first != 0) {
        int a = s.begin()->second;
        --p[a];
        --total;
        s.erase(s.begin());
        putchar('A' + a);
        s.emplace(-p[a], a);
        if (s.begin()->first != 0 && (total != 2 || p[a] != 0)) {
            int b = s.begin()->second;
            --p[b];
            --total;
            s.erase(s.begin());
            putchar('A' + b);
            s.emplace(-p[b], b);
        }
        putchar(s.begin()->first == 0? '\n' : ' ');
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
}
