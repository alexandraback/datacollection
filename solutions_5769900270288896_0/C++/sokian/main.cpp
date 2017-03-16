#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
#define in(n) int (n) = nxt()

using namespace std;

typedef long long ll;

inline int nxt() {
    int a;
    scanf("%d", &a);
    return a;
}

inline int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef pair<int, int> PII;

PII operator + (const PII &l, const PII &r) {
    return mp(l.x + r.x, l.y + r.y);
}
PII operator - (const PII &l, const PII &r) {
    return mp(l.x - r.x, l.y - r.y);
}

PII operator * (const PII &l, const int &r) {
    return mp(l.x * r, l.y * r);
}


inline void solve(int test) {
    int n = nxt();
    int m = nxt();
    int k = nxt();
    int N = 1 << (n * m);
    int ans = INT_MAX;
    for (int x = 0; x < N; ++x) {
        if (__builtin_popcount(x) == k) {
            int u[n][m];
            memset(u, 0, sizeof(u));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (x & (1 << (i * m + j))) {
                        u[i][j] = 1;
                    }
                }
            }
            int curans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i + 1 < n && u[i][j] && u[i + 1][j]) {
                        ++curans;
                    }
                    if (j + 1 < m && u[i][j] && u[i][j + 1]) {
                        ++curans;
                    }
                }
            }
            ans = min(ans, curans);
        }
    }
    cout << "Case #" << test << ": ";
    cout << ans << "\n";
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    srand(56435);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = nxt();
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }


    return 0;
}
