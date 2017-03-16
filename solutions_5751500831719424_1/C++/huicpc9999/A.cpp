#include <iostream>
#include <cstdio>
using namespace std;

#define oo (1<<29)
int n;
char lines[200][200];
int p[200], cnt[200];

int calc()
{
    for (int i = 0; i < n; ++i) p[i] = 0;
    int res = 0, flag = 1;
    while (flag)
    {
        for (int i = 1; i < n; ++i)
            if (lines[i][p[i]] != lines[0][p[0]]) return oo;
        for (int i = 0; i < n; ++i)
        {
            cnt[i] = 0;
            while (lines[i][p[i]+1] == lines[i][p[i]]) {p[i]++; cnt[i]++;}
            p[i]++;
            cnt[i]++;
            //printf("i  = %d, p = %d, cnt = %d\n", i, p[i], cnt[i]);
        }
        int num = 1, cost = oo;
        for (int t = 1; t <= 101; ++t)
        {
            int tmp = 0;
            for (int i = 0; i < n; ++i)
                tmp += (cnt[i]-t)>=0?(cnt[i]-t):(t-cnt[i]);
            if (tmp < cost) {cost = tmp; num = t;}
        }
        res += cost;
        //printf("res = %d\n", res);
        flag = 0;
        for (int i = 0; i < n; ++i)
            if (lines[i][p[i]] != '\0') flag = 1;
    }
    return res;
}

int main()
{
    //freopen("A-large.in","r", stdin);
    //freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", lines[i]);
        }
        int ans = calc();
        printf("Case #%d: ", cas);
        if (ans == oo) puts("Fegla Won");
        else printf("%d\n", ans);
    }
    return 0;
}
