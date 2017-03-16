#include <bits/stdc++.h>

using namespace std;

int trymin(int R, int C, int n, bool tl) {
    bool m[R][C];
    fill(m[0], m[R], 0);
    if (tl) m[0][0] = true;
    for (int r = 0; r < R; r++) 
        for (int c = 0; c < C; c++) {
            if (r == 0 && c == 0) continue;
            if (r > 0 && m[r-1][c]) continue;
            if (c > 0 && m[r][c-1]) continue;
            m[r][c] = true;
        }
    /*for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            putchar(m[r][c] ? 'X' : '.');
        }
        putchar('\n');
    }*/
    int ct = count(m[0], m[R], true);
    if (ct >= n)
        return 0;
    n -= ct;
    vector<int> f;
    for (int r = 0; r < R; r++) 
        for (int c = 0; c < C; c++) {
            if (m[r][c]) continue;
            int si = 0;
            if (r > 0 && m[r-1][c]) si++;
            if (c > 0 && m[r][c-1]) si++;
            if (r < R-1 && m[r+1][c]) si++;
            if (c < C-1 && m[r][c+1]) si++;
            f.push_back(si);
        }
    sort(f.begin(), f.end());
    int res = 0;
    for (int i = 0; i < n; i++)
        res += f[i];
    return res;
}

int solve() {
    int r, c, n;
    cin >> r >> c >> n;
    /*int l = r * c;
    int mas[l] = {0};
    fill(mas + l - n, mas + l, 1);
    int best = INT_MAX;
    int bestmas[l];
    do {
        int sc = 0;
        for (int rr = 0; rr < r; rr++) {
            for (int cc = 0; cc < c; cc++) {
                if (rr > 0 && mas[rr * c + cc] && mas[(rr-1) * c + cc])
                    sc++;
                if (cc > 0 && mas[rr * c + cc] && mas[rr * c + cc-1])
                    sc++;
            }
        }
        if (sc < best) {
            best = sc;
            copy(mas, mas+l, bestmas);
        }
    } while (next_permutation(mas, mas + l));
    for (int rr = 0; rr < r; rr++) {
        for (int cc = 0; cc < c; cc++) {
            putchar(bestmas[rr*c+cc] ? 'X' : '.');
        }
        printf("\n");
    }*/
    return min(trymin(r, c, n, true), trymin(r, c, n, false));
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        printf("Case #%d: %d\n", i, solve());
}
