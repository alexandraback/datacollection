# include <bits/stdc++.h>
using namespace std;
bool s[555][555];
int main(void)
{
    ifstream fi("b.in");
    ofstream fo("b.out");
    int t,n,m,k;
    fi>>t;
    for (int o = 1;o <= t;++o)
    {
        fi>>n>>m>>k;
        int p = n * m;
        int ans = INT_MAX;
        for (int i = 0,l = 1 << p;i < l;++i)
        {
            int cnt = 0;
            for (int j = 0;j < p;++j) if ((1 << j)&i) ++cnt;
            if (cnt == k)
            {
                for (int x = 0;x <= n + 1;++x)
                    for (int y = 0;y <= m+1;++y) s[x][y] = 0;
                for (int x = 1;x <= n;++x)
                    for (int y = 1;y <= m;++y) if ((1 << ((x - 1) * m + y - 1)) & i) s[x][y] = 1;else s[x][y] = 0;
                int mx = 0;
                for (int x = 1;x <= n;++x)
                    for (int y = 1;y <= m;++y) if (s[x][y]) mx += s[x+1][y] + s[x][y+1];
                ans = min(ans,mx);
            }
        }
        fo << "Case #" << o << ": " << ans << '\n',0;
    }
    return 0;
}

