#include <bits/stdc++.h>
using namespace std;

const int N = 16;
bool check[N][N];
int m;
int n;
int p;
int res;
int cur;

void backtrack(int x, int y) {
    if (y == n) {
        backtrack(x + 1, 0);
        return;
    }
    if (x == m) {
        if (p == 0) res = min(res, cur);
        return;
    }
    backtrack(x, y + 1);
    if (p > 0) {
        check[x][y] = true;
        --p;
        if (x > 0 && check[x - 1][y]) ++cur;
        if (y > 0 && check[x][y - 1]) ++cur;
        backtrack(x, y + 1);
        check[x][y] = false;
        ++p;
        if (x > 0 && check[x - 1][y]) --cur;
        if (y > 0 && check[x][y - 1]) --cur;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int nt; cin >> nt;
    for (int t = 1; t <= nt; ++t) {
        cin >> m >> n >> p;
        res = 1e9;
        backtrack(0, 0);
        cout << "Case #" << t << ": " << res << '\n';
    }
    return 0;
}
