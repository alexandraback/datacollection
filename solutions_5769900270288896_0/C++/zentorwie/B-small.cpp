#include <bits/stdc++.h>

using namespace std;

int cnt(int x) {
    int ans = 0;
    while (x) {
        if (x & 1) ans++;
        x >>= 1;
    }
    return ans;
}

int f[20][20][20];

int check(int x, int n, int m) {
    int ans = 0;
    int s1, s2;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            s1 = i * m + j;
            s2 = (i+1) * m + j;
            if (((x>>s1)&1) && ((x>>s2)&1)) ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            s1 = i*m+j;
            s2 = i*m+j+1;
            if (((x>>s1)&1) && ((x>>s2)&1)) ans++;
        }
    }
    return ans;
}

void gogo(int n, int m) {
    int tot = 1<<(n*m);
    int ct;
    for (int t = 0; t < tot; t++) {
        ct = cnt(t);
        int tmp = check(t, n, m);
        if (f[n][m][ct] == -1 || tmp < f[n][m][ct]) f[n][m][ct] = tmp;

    }
}

int calc(int r, int c, int n) {
    if (f[r][c][n] != -1) return f[r][c][n];
    else {
        gogo(r, c);
        return f[r][c][n];
    }
}



int main() {
    int T;
    memset(f, -1, sizeof(f));
    scanf("%d", &T);
    int R, C, N;
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d%d%d", &R, &C, &N);
        printf("Case #%d: %d\n", kase, calc(R, C, N));
    }
    return 0;
}
