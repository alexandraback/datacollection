#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int solve(int r, int c, int n) {
    if (n <= (r * c + 1) / 2)
        return 0;
    int best = -1u/2;
    REP (even, 2) {
        vector<vector<bool>> u(r, vector<bool>(c));
        int left = n;
        REP (i, r) REP (j, c) {
            if ((i + j) % 2 == even) {
                u[i][j] = true;
                --left;
            }
        }
        int unh = 0;
        assert(n >= 0);
        for (int k = 1; left > 0; ++k) {
            REP (i, r) REP (j, c) {
                if (left == 0) break;
                if (u[i][j])
                    continue;
                int d[] = {1, 0, -1, 0};
                int h = 0;
                REP (l, 4) {
                    int x = i + d[l], y = j + d[l ^ 1];
                    if (0 <= x && x < r && 0 <= y && y < c)
                        h += u[x][y];
                }
                assert(h >= k);
                if (h == k) {
                    u[i][j] = true;
                    unh += k;
                    --left;
                }
            }
        }
        best = min(best, unh);
    }
    return best;
}

int main() {
    int tests, tc = 0;
    for (cin >> tests; tc < tests; ) {
        printf("Case #%d: ", ++tc);
        int r, c, n;
        cin >> r >> c >> n;
        cout << solve(r, c, n) << endl;
    }
    return 0;
}
