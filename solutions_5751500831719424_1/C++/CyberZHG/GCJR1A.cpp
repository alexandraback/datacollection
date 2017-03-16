#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 5;
const int MAXL = 100 + 5;

char s[MAXN][MAXL];
int n[MAXN];
int ch[MAXN][MAXL];
int num[MAXN][MAXL];
int maxLen[MAXN];

void divide(int &n, int ch[MAXL], int num[MAXL], char *str)
{
    n = 0;
    ch[n] = str[0];
    num[n++] = 1;
    for (int i = 1; str[i]; ++i)
    {
        if (str[i] == str[i - 1])
        {
            ++num[n - 1];
        }
        else
        {
            ch[n] = str[i];
            num[n++] = 1;
        }
    }
}

int getDist(int a, int b)
{
    int d = 0;
    if (n[a] != n[b])
    {
        return -1;
    }
    for (int i = 0; i < n[a]; ++i)
    {
        if (ch[a][i] != ch[b][i])
        {
            return -1;
        }
        d += abs(num[a][i] - num[b][i]);
    }
    return d;
}
int N;
int mini(int index)
{
    int mi = 0x7FFFFFFF;
    for (int i = 1; i <= 100; ++i)
    {
        int temp = 0;
        for (int j = 1; j <= N; ++j)
        {
            temp += abs(num[j][index] - i);
        }
        mi = min(mi, temp);
    }
    return mi;
}

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &N);
        memset(maxLen, 1, sizeof(maxLen));
        for (int i = 1; i <= N; ++i)
        {
            scanf("%s", s[i]);
            divide(n[i], ch[i], num[i], s[i]);
        }
        printf("Case #%d: ", cas);
        int d = 0;
        for (int i = 2; i <= N; ++i)
        {
            if (getDist(1, i) == -1)
            {
                d = -1;
            }
        }
        if (d == -1)
        {
            puts("Fegla Won");
        }
        else
        {
            for (int i = 0; i < n[1]; ++i)
            {
                d += mini(i);
            }
            printf("%d\n", d);
        }
    }
    return 0;
}
