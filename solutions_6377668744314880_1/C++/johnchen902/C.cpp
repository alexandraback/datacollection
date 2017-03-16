#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct P {
    int x, y;
} p[3000], q[2999];

int count(int l, int r, int n) {
    if(r < l)
        r += n;
    return r - l + 1;
}

bool bad(const P& c, const P& l, const P& r) {
    long long cross = (l.x - c.x) * 1LL * (r.y - c.y) - (r.x - c.x) * 1LL * (l.y - c.y);
    long long dot   = (l.x - c.x) * 1LL * (r.x - c.x) + (l.y - c.y) * 1LL * (r.y - c.y);
    return cross > 0 || (cross == 0 && dot > 0);
}

int solve(int n, int id) {
    if(n <= 3)
        return 0;

    for(int i = 0, j = 0; i < n; i++)
        if(i != id)
            q[j++] = p[i];
    sort(q, q + n - 1, [id](const P& lhs, const P& rhs) {
         return atan2(lhs.y - p[id].y, lhs.x - p[id].x) < atan2(rhs.y - p[id].y, rhs.x - p[id].x);
    });
    int ans = n - 1 - 2;
    for(int l = 0, r = 1; l < n - 1; l++) {
        while(l != r && bad(p[id], q[l], q[r]))
            r = (r + 1) % (n - 1);
        if(l == r)
            return 0;
        ans = min(ans, count(l, r, n - 1) - 2);
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
            scanf("%d %d", &p[j].x, &p[j].y);
        fprintf(stderr, "Case #%d:\n", i);
        printf("Case #%d:\n", i);
        for(int j = 0; j < n; j++)
            printf("%d\n", solve(n, j));
    }
}
