#include <bits/stdc++.h>

using namespace std;

int solve() {
    int r, c, n;
    cin >> r >> c >> n;
    int l = r * c;
    int mas[l] = {0};
    fill(mas + l - n, mas + l, 1);
    int best = INT_MAX;
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
        best = min(best, sc);
    } while (next_permutation(mas, mas + l));
    return best;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        printf("Case #%d: %d\n", i, solve());
}
