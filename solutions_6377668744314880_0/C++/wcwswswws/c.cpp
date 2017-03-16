#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct Tree
{
    int x, y;
} trees[3000], others[3000];

Tree org;

bool cmp(const Tree &a, const Tree &b)
{
    long long x1 = a.x, y1 = a.y;
    long long x2 = b.x, y2 = b.y;
    if (y1 < 0) { x1 = -x1; y1 = -y1; }
    if (y2 < 0) { x2 = -x2; y2 = -y2; }
    return (x1 * y2 - x2 * y1 > (long long)0);
}

bool ThroughOrg(Tree &a, Tree &b)
{
    long long x1 = a.x, y1 = a.y;
    long long x2 = b.x, y2 = b.y;
    if (y1 < 0) { x1 = -x1; y1 = -y1; }
    if (y2 < 0) { x2 = -x2; y2 = -y2; }
    return (x1 * y2 - x2 * y1 == (long long)0);

}

int Work(int n, int cur)
{
    int ans = n - 1;
    int left = 0, right = 0, in = 0, out = 0, m = 0;
    org = trees[cur];
    for (int i = 0; i < n; i++)
    if (i != cur)
    {
        others[m].x = trees[i].x - trees[cur].x;
        others[m].y = trees[i].y - trees[cur].y;
        if (others[m].y != 0)
        {
            if (others[m].y > 0) { left++; }
            else { right++; }
            m++;
        } else
        {
            if (others[m].x > 0) { out++; }
            else { in++; }
        }
    }

    ans = min(min(left, right), ans);
    left = left + in;
    right = right + out;
    if (m == 0) { return ans; }
    sort(others, others + m, cmp);
    int i = 0;
    while (i < m)
    {
        int j = i + 1;
        in = 0; out = 0;
        if (others[i].y > 0) { left--; out++; }
        else { right--; in++; }

        while ((j < m) && (ThroughOrg(others[i], others[j])))
        {
            if (others[j].y > 0) { left--; out++; }
            else { right--; in++; }
            j++;
        }

        ans = min(min(left, right), ans);
        left = left + in;
        right = right + out;
        i = j;
    }
    return ans;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case #%d:\n", t);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &trees[i].x, &trees[i].y);
        }

        for (int i = 0; i < n; i++) { printf("%d\n", Work(n, i)); }
    }
    return 0;
}
