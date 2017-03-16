#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    long long x, y;
    friend bool operator == (const Point &l, const Point &r)
    {
        return l.x == r.x && l.y == r.y;
    }
    friend bool operator < (const Point &l, const Point &r)
    {
        return l.y < r.y || (l.y == r.y && l.x < r.x);
    }
};
const int N = 30, M = 1 << 16;

bool mult(Point sp, Point ep, Point op)
{
    return (sp.x - op.x) * (ep.y - op.y) > (ep.x - op.x) * (sp.y - op.y);
}
int graham(Point pnt[], int n, Point res[])
{
    int i, len, k = 0, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0; res[0] = pnt[0];
    if (n == 1) return 1; res[1] = pnt[1];
    if (n == 2) return 2; res[2] = pnt[2];
    for (i = 2; i < n; i++)
    {
        while (top && mult(pnt[i], res[top], res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top; 
    res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--) 
    {
        while (top != len && mult(pnt[i], res[top], res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    return top;
}
int main()
{
    int T, n, ans[N];
    Point pnt[N], res[N], data[N];
    scanf("%d", &T);
    for (int tst = 1; tst <= T; ++tst)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lld%lld", &data[i].x, &data[i].y);
        memset(ans, -1, sizeof(ans));
        printf("Case #%d:\n", tst);
        for (int mask = (1 << n) - 1; mask; --mask)
        {
            int use = mask, m = 0, i = 0;
            while (use)
            {
                if (use & 1)
                    pnt[m++] = data[i];
                use >>= 1;
                i++;
            }
            int p = graham(pnt, m, res), remove = n - m;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < p; ++j)
                    if (data[i] == res[j])
                    {
                        if (ans[i] == -1 || remove < ans[i])
                            ans[i] = remove;
                        break;
                    }
            }
        }
        for (int i = 0; i < n; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
