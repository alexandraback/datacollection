# include <bits/stdc++.h>
using namespace std;
bitset < 10005 > s[10005];
int n,m,k;
void color(int ok)
{
    if (ok)
    {
        for (int i = 1;i <= n && k;++i)
            for (int j = 1;j <= m && k;++j) if ((i&1) == (j&1) && !s[i][j]) s[i][j] = 1,--k;
    }
    else
    {
        for (int i = 1;i <= n && k;++i)
            for (int j = 1;j <= m && k;++j)
                if ((i&1) != (j&1) && !s[i][j]) s[i][j] = 1,--k;
    }
}
int query(void)
{
    int ans = 0;
    for (int i = 1;i <= n;++i)
        for (int j = 1;j <= m;++j)  if (s[i][j]) ans += s[i+1][j] + s[i][j+1];
    return ans;
}
int main(void)
{
    ifstream fi("b.in");
    ofstream fo("b.out");
    int t;
    fi>>t;
    for (int o = 1;o <= t;++o)
    {
        fi>>n>>m>>k;
        for (int i = 0;i <= n + 1;++i)
            for (int j = 0;j <= m + 1;++j) s[i][j] = 0;
        int p = k;
        color(1);
        if (k && !s[1][1]) s[1][1] = 1,--k;
        if (k && !s[1][m]) s[1][m] = 1,--k;
        if (k && !s[n][1]) s[n][1] = 1,--k;
        if (k && !s[n][m]) s[n][m] = 1,--k;
        for (int i = 1;i <= n;++i) if (k && !s[i][1]) s[i][1] = 1,--k;
        for (int i = 1;i <= n;++i) if (k && !s[i][m]) s[i][m] = 1,--k;
        for (int i = 1;i <= m;++i) if (k && !s[1][i]) s[1][i] = 1,--k;
        for (int i = 1;i <= m;++i) if (k && !s[n][i]) s[n][i] = 1,--k;
        color(0);
        int ans = query();
        k = p;
        for (int i = 0;i <= n + 1;++i)
            for (int j = 0;j <= m + 1;++j) s[i][j] = 0;
        color(0);
        if (k && !s[1][1]) s[1][1] = 1,--k;
        if (k && !s[1][m]) s[1][m] = 1,--k;
        if (k && !s[n][1]) s[n][1] = 1,--k;
        if (k && !s[n][m]) s[n][m] = 1,--k;
        for (int i = 1;i <= n;++i) if (k && !s[i][1]) s[i][1] = 1,--k;
        for (int i = 1;i <= n;++i) if (k && !s[i][m]) s[i][m] = 1,--k;
        for (int i = 1;i <= m;++i) if (k && !s[1][i]) s[1][i] = 1,--k;
        for (int i = 1;i <= m;++i) if (k && !s[n][i]) s[n][i] = 1,--k;
        color(1);
        ans = min(ans,query());
        fo << "Case #" << o << ": " << ans << '\n',0;
    }
    return 0;
}

