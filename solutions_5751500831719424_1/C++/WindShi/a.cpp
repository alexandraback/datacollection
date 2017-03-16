#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, a[101][101], v[101][101], len[101], n;
char str[101];

int main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        scanf("%d", &n);
        printf("Case #%d: ", uu);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            int L = strlen(str);
            len[i] = 0;
            for (int j = 0; j < L; j++)
                if (!j || str[j] != str[j - 1])
                {
                   ++len[i];
                   a[i][len[i]] = str[j];
                   v[i][len[i]] = 0;
                   for (int k = j; k < L; k++)
                       if (str[k] != str[j]) break;
                       else ++v[i][len[i]];
                }
        }
        bool ok = true;
        for (int i = 1; i <= n && ok; i++)
            if (len[i] != len[1]) ok = false;
        for (int j = 1; j <= len[1] && ok; j++)
            for (int i = 1; i <= n && ok; i++) 
                if (a[i][j] != a[1][j]) ok = false;
        if (!ok) printf("Fegla Won\n");
        else
        {
            int ans = 0;
            for (int i = 1; i <= len[1]; i++)
            {
                int Min = 1 << 30;
                for (int j = 1; j <= n; j++)
                {
                    int will = 0;
                    for (int k = 1; k <= n; k++)
                        will += abs(v[j][i] - v[k][i]);
                    Min = min(Min, will);
                }
                ans += Min;
            }
            printf("%d\n", ans);
        }
    }
}
