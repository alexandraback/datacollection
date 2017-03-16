#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }

inline ll getll() { unsigned int c; ll x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getll(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

void print_case(int test_case) { printf("Case #%d: ", test_case); }

template<class T> T gcd(T x, T y) { T r; if (x < y) r = x, x = y, y = r; if (y == 0) return x; r = x % y, x = y, y = r; if (y == 0) return x; int k = 0; while (!((x | y) & 1)) k++, x >>= 1, y >>= 1; while (!(x & 1)) x >>= 1; while (!(y & 1)) y >>= 1; for (; x != y; ) { if (x < y) r = x, x = y, y = r; r = (x - y) >> 1; while (!(r & 1)) r >>= 1; x = r; } return x << k; }
template<class T> T lcm(T x, T y) { return x / gcd(x, y) * y; }
template<class T> pair<T, T> extended_gcd(T a, T b) {
    T x = 0, y = 1, px = 1, py = 0, q, aa, xx, yy;
    while (b) {
        q = a / b, aa = a, a = b, b = aa % b;
        xx = x, x = px - q * x, px = xx;
        yy = y, y = py - q * y, py = yy;
    }
    return make_pair(px, py);
}




ll n, m;
ll ms[10];

ll ttl[10];

void solve_case() {
    int i, j;
    m = getll(), n = getll();
    for (i = 0; i < m; i++) ms[i] = getll();

    ll lm = 1;
    for (i = 0; i < m; i++) lm = lcm(lm, ms[i]);

    ll proc = 0;
    for (i = 0; i < m; i++) proc += lm / ms[i];

    n = n % proc;

    if (n == 0) n = proc;

    for (i = 0; i < m; i++) ttl[i] = 0;

    ll res = m;
    for (i = 0; i < n; i++) {
        int who = 0;
        int mn = 1 << 30;
        for (j = 0; j < m; j++) {
            if (mn > ttl[j]) {
                mn = ttl[j], who = j;
            }
        }
        for (j = 0; j < m; j++) {
            ttl[j] -= mn;
        }
        ttl[who] = ms[who];
        if (i == n - 1) {
            res = who + 1;
        }
    }
    printf("%lld\n", res);
    return;
}

int main () {
    int test_count, test_case = getint();
    for (test_count = 0; test_count < test_case; test_count++) {
        print_case(test_count + 1);
        solve_case();
    }
    return 0;
}
