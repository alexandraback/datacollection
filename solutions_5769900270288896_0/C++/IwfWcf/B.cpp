#include <stdio.h>

const int N = 16;

int r, c;
int best;
bool f[N];

int score(int n)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (!f[i])
        {
            continue;
        }
        int left = i - 1;
        int up = i - c;
        int right = i + 1;
        int down = i + c;
        if (left >= 0 && f[left] && left % c < i % c)
        {
            ret++;
        }
        if (up >= 0 && f[up])
        {
            ret++;
        }
        if (right < n && f[right] && right % c > i % c)
        {
            ret++;
        }
        if (down < n && f[down])
        {
            ret++;
        }
    }
    return ret;
}

void dfs(int len, int last, int n)
{
    if (len == 0)
    {
        int now = score(n);
        if (now < best)
        {
            best = now;
        }
        return;
    }
    for (int i = last + 1; i <= n - len; i++)
    {
        f[i] = true;
        dfs(len - 1, i, n);
        f[i] = false;
        if (best == 0)
        {
            return;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++)
    {
        int n;
        scanf("%d%d%d", &r, &c, &n);
        best = 1 << 30;
        dfs(n, -1, r * c);
        printf("Case #%d: %d\n", cases, best / 2);
    }
    return 0;
}
