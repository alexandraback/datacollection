#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

const int inf = 1000*1000*1000+1;

struct P {
    ll x, y; int i;
    P() : x(0ll), y(0ll) { }
    P(ll xx, ll yy) : x(xx), y(yy) { }
    bool operator<(const P &p) const {
        if (y == p.y) return x < p.x;
        else return y < p.y;
    }
    bool operator==(const P &p) const {
        return x == p.x && y == p.y;
    }
};

P operator-(P a, P b) { return P(a.x-b.x, a.y-b.y); }
ll operator^(P a, P b) { return a.x*b.y - a.y*b.x; }
ll dot(P a, P b) { return a.x*b.x + a.y*b.y; }
bool left(P a, P b, P c) { return ((b-a)^(c-b)) > 0ll; }
bool right(P a, P b, P c) { return ((b-a)^(c-b)) < 0ll; }
bool coll(P a, P b, P c) { return ((b-a)^(c-b)) == 0ll; }

int N;
P p[3005];
int ans[3005];

ll sign(ll a) {
    if (a > 0ll) return 1ll;
    else if (a < 0ll) return -1ll;
    else return 0ll;
}

P origin;
bool dmp(const P &a, const P &b) {
    return right(origin, b, a);
}

P cur, prev;
bool cmp(const P &a, const P &b) {
    if (coll(cur, b, a)) {
        if (sign(dot(a-cur, prev-cur)) == sign(dot(b-cur, prev-cur)))
            return dot(a-cur, a-cur) < dot(b-cur, b-cur);
        else return sign(dot(a-cur, prev-cur)) < sign(dot(b-cur, prev-cur));
    }
    else return right(cur, b, a);
    //printf("(%lld,%lld),(%lld,%lld),(%lld,%lld), %d\n", cur.x, cur.y,
    //b.x, b.y, a.x, a.y, right(cur, b, a) ? 1 : 0);
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
        for (int i = 0; i < N; i++) p[i].i = i;
        std::fill(ans, ans+N, inf);

        if (N <= 3) {
            printf("Case #%d:\n", t);
            for (int i = 0; i < N; i++) printf("%d\n", 0);
            continue;
        }

        std::swap(*std::min_element(p, p+N), p[0]);
        P start = origin = p[0]; std::sort(p, p+N, dmp);

        cur = p[0], prev = p[N-1];
        while (true) {
            //printf("cur = (%lld,%lld), prev = (%lld,%lld)\n", cur.x, cur.y, prev.x, prev.y);
            //for (int i = 0; i < N; i++) printf("(%lld,%lld)%c", p[i].x, p[i].y, " \n"[i == N-1]);
            std::sort(p+1, p+N, cmp);
            //for (int i = 0; i < N; i++) printf("(%lld,%lld)%c", p[i].x, p[i].y, " \n"[i == N-1]);
            int s = 1, e = 1;
            while (s < N) {
                while (e < N && coll(p[0], p[s], p[e])) e++;
                for (int i = s; i < e; i++) ans[p[i].i] = std::min(ans[p[i].i], s-1);
                s = e;
            }
            cur = p[1];
            prev = p[0];
            std::swap(p[0], p[1]);
            if (cur == start) break;
        }
        printf("Case #%d:\n", t);
        for (int i = 0; i < N; i++) printf("%d\n", ans[i]);
    }
}

