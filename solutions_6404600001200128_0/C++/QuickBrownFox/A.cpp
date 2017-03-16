#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getstr(char *s) { int c, n = 0; while ((c = gc()) <= ' ') { if (!~c) exit(0); } do { s[n++] = c; } while ((c = gc()) > ' ' ); s[n] = 0; return n; }
template<class T> inline bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> inline bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }


int n;
int as[1111];

void print_case(int test_case) { printf("Case #%d: ", test_case); }

void solve_case() {
    int i, j;
    n = getint();
    for (i = 0; i < n; i++) as[i] = getint();

    int res1 = 0;
    int max_step = 0;
    for (i = 0; i < n - 1; i++) {
        int now = as[i];
        int nxt = as[i + 1];
        if (nxt < now) {
            res1 += now - nxt;
            chmax(max_step, now - nxt);
        }
    }
    int res2 = 0;
    for (i = 0; i < n - 1; i++) {
        int now = as[i];
        res2 += min(now, max_step);
    }

    printf("%d %d\n", res1, res2);

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
