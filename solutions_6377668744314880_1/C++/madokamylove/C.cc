#include <cstdio>
#include <algorithm>
using namespace std;


struct P {
    long long x, y;
    long long operator * (const P &b) const {
        return x * b.y - y * b.x;
    }
    P operator - (const P &b) const {
        P res;
        res.x = x - b.x;
        res.y = y - b.y;
        return res;
    }
};

P pt[6010], st[6010];

int get(P xx) {
    long long x = xx.x, y = xx.y;
    if (x > 0 && y >= 0) return 0;
    if (y > 0 && x <= 0) return 1;
    if (x < 0 && y <= 0) return 2;
    return 3;
}

bool cmp(P x, P y) {
    int id1 = get(x), id2 = get(y);
    if (id1 != id2) {
        return id1 < id2;
    }
    return (x * y) > 0;
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas ++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%I64d%I64d", &pt[i].x, &pt[i].y);
        }
        printf("Case #%d:\n", cas);
        fprintf(stderr, "Case #%d:\n", cas);
        for (int i = 0; i < n; i ++) {
            int cnt = 0;
            for (int j = 0; j < n; j ++) {
                if (i == j) {
                    continue;
                }
                st[cnt ++] = pt[j] - pt[i];
            }
            sort(st, st + cnt, cmp);
            for (int i = cnt; i < 2 * cnt; i ++) {
                st[i] = st[i - cnt];
            }
            int R = 0, res = 0;
            for (int i = 0; i < cnt; i ++) {
                while (R < i + cnt && (st[i] * st[R]) >= 0) {
                    R ++;
                }
                R --;
                res = max(res, R - i + 1);
            }
            printf("%d\n", n - res - 1);
            //fprintf(stderr, "%d\n", n - res - 1);
        }
    }
    return 0;
}