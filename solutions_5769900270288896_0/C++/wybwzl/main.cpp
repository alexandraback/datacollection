#include<stdio.h>
#include<string.h>
#include<algorithm>
typedef long long LL;
int a[10010], b[10010];
int get(int i, int j, int R, int C) {
    if(R == 1) {
        if(C == 1) {
            return 0;
        }
        if(j == 0 || j == C - 1) {
            return 1;
        }
        return 2;
    }
    if(i == 0 && (j == 0 || j == C - 1)) {
        return 2;
    }
    if(i == R - 1 && (j == 0 || j == C - 1)) {
        return 2;
    }
    if(i == 0 || i == R - 1 || j == 0 || j == C - 1) {
        return 3;
    }
    return 4;
}
bool cmp(const int &x, const int &y) {
    return x > y;
}
int main() {
    //freopen("input.txt", "rb", stdin);
    freopen("B-small-attempt0.in", "rb", stdin);
    freopen("output.txt", "wb", stdout);
    int t;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt ++) {
        int R, C, N;
        scanf("%d%d%d", &R, &C, &N);
        if(R > C) {
            std::swap(R, C);
        }
        int ans;
        if(N <= (R * C + 1) / 2) {
            ans = 0;
        } else {
            ans = (C - 1) * R + C * (R - 1);
            int an = 0, bn = 0;
            for(int i = 0; i < R; i ++) {
                for(int j = 0; j < C; j ++) {
                    if((i + j) % 2 == 0) {
                        a[an ++] = get(i, j, R, C);
                    } else {
                        b[bn ++] = get(i, j, R, C);
                    }
                }
            }
            std::sort(a, a + an, cmp);
            std::sort(b, b + bn, cmp);
            int A = 0, B = 0;
            for(int i = 0; i < R * C - N; i ++) {
                A += a[i];
                B += b[i];
            }
            ans -= std::max(A, B);
        }
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
