/**
 * Copyright (c) 2015 Authors. All rights reserved.
 * 
 * FileName: C.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-04-18
 */
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

typedef complex<LL> Point;
typedef complex<LL> Vector;
#define X real()
#define Y imag()

LL cross(Vector u, Vector v) { return u.X * v.Y - u.Y * v.X; }

typedef vector<Point> Polygon;

const int maxn = 3000 + 5;

int n;
Point p[maxn];
int res[maxn], a[maxn], m;
vector<int> vec;

bool on_left(int i, const vector<int> &v)
{
        Point p1 = p[*++v.rbegin()], p2 = p[v.back()];
        return cross(p2 - p1, p[i] - p1) < 0;
}

bool cmp(int a, int b)
{
        return p[a].X != p[b].X? p[a].X < p[b].X: p[a].Y < p[b].Y;
}

void convex_hull(int a[], int n, vector<int> &v)
{
        v.clear();
        sort(a, a + n, cmp);
        for (int i = 0; i < n; ++i) {
                while (v.size() > 1 && on_left(a[i], v)) v.pop_back();
                v.push_back(a[i]);
        }
        int k = v.size();
        for (int i = n - 2; i >= 0; --i) {
                while (v.size() > k && on_left(a[i], v)) v.pop_back();
                v.push_back(a[i]);
        }
        if (n > 1) v.pop_back();
}

int main()
{
        int T, cas = 0;
        scanf("%d", &T);

        while (T--) {
                scanf("%d", &n);
                rep(i,n) {
                        int x, y;
                        scanf("%d%d", &x, &y);
                        p[i] = Point(x, y);
                }
                memset(res, 0x3f, sizeof(res));
                rep(S,1<<n) {
                        m = 0;
                        rep(i,n) if (S & (1 << i)) a[m++] = i;
                        convex_hull(a, m, vec);
                        foreach(it,vec) res[*it] = min(res[*it], n - m);
                }
                printf("Case #%d:\n", ++cas);
                rep(i,n) printf("%d\n", res[i]);
        }

        return 0;
}
