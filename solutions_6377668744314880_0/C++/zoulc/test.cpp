#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define eps 1e-8
#define inf 1<<29
const double pi = acos(-1.0);

struct point
{
    int x, y, index;
} v[1000];

int ans[1000], N;

int det(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - x2 * y1;
}

int cross(point o, point a, point b)
{
    return det(a.x - o.x, a.y - o.y, b.x - o.x, b.y - o.y);
}

double f(int x)
{
    return x * x * 1.0;
}

double dis(point a, point b)
{
    return sqrt( f(a.x - b.x) + f(a.y - b.y) );
}

bool cmp(point a, point b)
{
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

void graham(point p[], int n)
{
    if(n <= 3) {
        for (int i = 0; i < n; ++i)
            if (ans[p[i].index] > N - n)
                ans[p[i].index] = N - n;
        return;
    }
    int i;
    sort(p, p + n, cmp);
    int top = 0;
    point res[1003];
    for(i = 0; i < n; i++)
    {
        while(top >= 2 && cross(res[top-2], res[top-1], p[i]) < 0)
            top--;
        res[top++] = p[i];
    }
    int t = top + 1;
    for(i = n - 2; i >= 0; i--)
    {
        while(top >= t && cross(res[top-2], res[top-1], p[i]) < 0)
            top--;
        res[top++] = p[i];
    }
    res[top++] = p[0];
    for (i = 0; i < top; i++)
        if (ans[res[i].index] > N - n)
            ans[res[i].index] = N - n;
}

bool vis[1000];

void dfs(int dep) {
    if (dep == N) {
        vector<point> temp;
        for (int i = 0; i < N; ++i)
            if (vis[i])
                temp.push_back(v[i]);
        point* p = temp.data();
        //for (int i = 0; i < temp.size(); ++i)
        //    printf("%d ", temp[i].index);
        //printf("\n");
        graham(p, temp.size());
        return;
    }
    vis[dep] = false;
    dfs(dep + 1);
    vis[dep] = true;
    dfs(dep + 1);
}

int main() {
    freopen("convex.in", "r", stdin);
    freopen("convex.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d %d", &v[i].x, &v[i].y);
        for (int i = 0; i < N; ++i)
            v[i].index = i;
        memset(vis, 0, sizeof(vis));
        memset(ans, 127, sizeof(ans));
        dfs(0);
        printf("Case #%d:\n", Case);
        for (int i = 0; i < N; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
