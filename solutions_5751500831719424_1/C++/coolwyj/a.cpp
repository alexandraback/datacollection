#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define inf 1000000000
int Cas = 1, t, n, a[MAXN][MAXN];
string s[MAXN];
string goal;
bool check()
{
    memset(a, 0, sizeof(a));
    goal.clear();
    for (int i = 0; i < s[1].length(); i ++) {
        if (i == 0) 
        {
            goal += s[1][i];
            a[1][goal.length()] ++;
        } 
        else 
        {
            if (s[1][i] == goal[goal.length() - 1]) 
            {
                a[1][goal.length()] ++;
                continue;
            }
            else 
            {
                goal += s[1][i];
                a[1][goal.length()] ++;
            }
        }
    }
    for (int i = 2; i <= n; i ++) 
    {
        string tmp;
        for (int j = 0; j < s[i].length(); j ++)
        {
            if (j == 0) 
            {
                tmp += s[i][j];
                a[i][tmp.length()] ++;
            } 
            else {
                if (s[i][j] == tmp[tmp.length() - 1]) 
                {
                    a[i][tmp.length()] ++;
                    continue;
                } 
                else 
                {
                    tmp += s[i][j];a[i][tmp.length()] ++;
                }
            }
        }
        if (goal != tmp) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &t);
    while (t --) 
    {
        printf("Case #%d: ", Cas ++);
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            cin >> s[i];
        if (check()) 
        {
            int ans = 0;
            for (int i = 1; i <= goal.length(); i ++) 
            {
                int now = inf;
                for (int j = 1; j <= 100; j ++) 
                {
                    int tmp = 0;
                    for (int k = 1; k <= n; k ++) 
                        tmp += abs(a[k][i] - j);
                    now = min(now, tmp);
                }
                ans += now;
            }
            printf("%d\n", ans);
        }
        else printf("Fegla Won\n");
    }
    return 0;
} 

