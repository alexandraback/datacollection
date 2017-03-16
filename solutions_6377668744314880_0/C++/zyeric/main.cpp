#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;

struct point
{
    int x, y;
    point(){}
    point(int x, int y)
    {
        this -> x = x, this -> y = y;
    }
    point operator + (const point &p)
    {
        return point(this -> x + p.x, this -> y + p.y);
    }
    point operator - (const point &p)
    {
        return point(this -> x - p.x, this -> y - p.y);
    }
    double operator * (const point &p)
    {
        return 1ll * this -> x * p.x + 1ll * this -> y * p.y;
    }
    double dot(const point &p)
    {
        return 1ll * this -> x * p.y - 1ll * p.x * this -> y;
    }
    double len()
    {
        return sqrt(1ll * this -> x * this -> x + 1ll * this -> y * this -> y);
    }
};

typedef point P;

bool cmp(const P &p,const P &q) {
    if (p.x == q.x)  return p.y<q.y;
    return p.x < q.x;
}

vector<P> convex_hull(P * ps, int n) {
    sort(ps, ps + n, cmp);
    int k = 0;
    vector<P> qs(n * 2);
    for (int i = 0; i < n; ++ i) {
        while ( k > 1 && (qs[k - 1] - qs[k - 2]).dot(ps[i] - qs[k - 1]) <= 0)  k--;
        qs[k ++] = ps[i];
    }
    for (int i = n-2, t = k; i >= 0; -- i) {
        while ( k > t && (qs[k - 1] - qs[k - 2]).dot(ps[i] - qs[k - 1]) <= 0)  k--;
        qs[k ++]=ps[i];
    }
    qs.resize(k - 1);
    return qs;
}

P a[20], b[20];

void work()
{
    int n;
    int i, j, k;
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    REP(i, n) {
        int ans = max(0, n - 3);
        REP(j, (1 << n)) {
            if ((j & (1 << i)) == 0)    continue;
            int cnt = 0;
            REP(k, n) {
                if ((j & (1 << k))){
                    b[cnt ++] = a[k];
                }
            }
            if (cnt <= 3)   continue;
            vector<point> tt = convex_hull(b, cnt);
            point now = a[i];
            bool suc = true;
            int size = (int)tt.size();
            REP(k, size) {
                int nxt = (k + 1) % size;
                if ((tt[k] - now).dot(now - tt[nxt]) == 0) {
                    suc = false;
                    break;
                }
            }
            if (!suc) {
                ans = min(ans, n - cnt);
            }
        }
        printf("%d\n", ans);
    }
}

int main()
{
    ios :: sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    int kase = 1;
    while (T --) {
        printf("Case #%d:\n", kase ++);
        work();
    }
    return 0;
}