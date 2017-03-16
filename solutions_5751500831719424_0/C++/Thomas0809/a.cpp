#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[111][111], num[111];
char a[111][111], s[111];
int n, T, ans;

int check()
{
    for (int i = 0; i < n; i++)
        if (num[i] != num[0])
            return -1;
    int res = 0;
    for (int i = 0; i < num[0]; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][j] != a[i][0])
                return -1;
        sort(b[i], b[i] + n);
        for (int j = 0; j < n; j++)
            res += abs(b[i][j] - b[i][n / 2]);
    }
    return res;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            num[i] = 0;
            for (int j = 0; s[j] != 0; j++)
            {
                a[num[i]][i] = s[j];
                b[num[i]][i] = 1;
                while (s[j + 1] == s[j]) j++, b[num[i]][i]++;
                num[i]++;
            }
        }
        ans = check();
        printf("Case #%d: ", tt + 1);
        if (ans == -1)
            printf("Fegla Won\n");
        else
            printf("%d\n", ans);
    }
}
