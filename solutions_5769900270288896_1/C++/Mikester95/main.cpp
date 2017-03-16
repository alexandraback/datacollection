#include <iostream>
#include <algorithm>
#include <fstream>

#define inf 1000000000
#define eps 1e-10

using namespace std;

ifstream fin ("test.in");
ofstream fout("test.out");

bool M[10010][10010];
int dir1[4] = {0,0,-1,1};
int dir2[4] = {-1,1,0,0};
int v[10010];

int solve()
{
    int n,m,p;
    fin >> n >> m >> p;

    int ok = 1;

    int mid = n*m/2;
    if (n*m % 2 == 1)
        mid++;


    if (p > mid)
    {
        ok = 0;
    }
    else ok = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if(ok == j%2)
            {
                M[i][j] = 1;
                --p;
            }
        }
        ok = 1-ok;
    }

    if (p <= 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                M[i][j] = 0;
        }
        return 0;
    }

    int t = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int cnt = 0;

            if (M[i][j] == 0)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int ii = i+dir1[k];
                    int jj = j+dir2[k];

                    if (M[ii][jj] == 1)
                    {
                        ++cnt;
                    }
                }
                v[++t] = cnt;
            }
        }
    }

    sort(v+1,v+t+1);

    int ans = 0;

    for (int i = 1; i <= p; ++i)
    {
        ans += v[i];
    }

        for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            M[i][j] = 0;
    }

    return ans;
}

int main()
{
    int test;
    fin >> test;

    for (int k = 1; k <= test; ++k)
    {
        int ans = solve();

        fout << "Case #" << k << ": " << ans << "\n";
    }
}
