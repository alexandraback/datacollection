#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;

char s[1000][1000];
int cot[1000][1000];

int main()
{
    freopen("A.txt", "r", stdin);
    freopen("A-output.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T ++)
    {
        int n;
        scanf("%d", &n);
        bool flag = true;
        memset(cot, 0, sizeof(cot));
        for (int i = 0; i < n; i ++)
        {
            scanf("%s", s[i]);
            for (int j = 1, tot = 0; s[i][j - 1]; j ++)
            {
                if (s[i][j] != s[i][tot])
                {
                    s[i][++ tot] = s[i][j];
                }
                cot[tot][i] ++;
            }
            if (i && strcmp(s[i], s[i - 1]))
            {
                flag = false;
            }
        }
        if (! flag)
        {
            printf("Case #%d: Fegla Won\n", T);
            continue;
        }
        int len = strlen(s[0]);
        int ans = 0;
        for (int i = 0; i < len; i ++)
        {
            sort(cot[i], cot[i] + n);
            for (int j = 0; j < n; j ++)
            {
                ans += fabs(cot[i][j] - cot[i][(n - 1) >> 1]);
            }
        }
        printf("Case #%d: %d\n", T, ans);
    }
    return 0;
}
