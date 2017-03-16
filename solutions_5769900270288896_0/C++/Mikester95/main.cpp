#include <iostream>
#include <fstream>

#define inf 1000000000

using namespace std;

ifstream fin ("test.in");
ofstream fout("test.out");

bool chosen[30][30];
int n,m,p,ans,cnt;

int nexti (int i, int j)
{
    if (j != m-1)
        return i;
    return i+1;
}

int nextj(int i, int j)
{
    if (j != m-1)
        return j+1;
    return 0;
}

void back(int i, int j)
{
    if (cnt == p)
    {
        int cr =0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i != n-1)
                {
                    if (chosen[i][j] && chosen[i+1][j])
                        ++cr;
                }
                if (j != m-1)
                {
                    if (chosen[i][j] && chosen[i][j+1])
                        ++cr;
                }
            }
        }

        ans = min(ans, cr);
        return;
    }

    if (i == n)
        return;

    back(nexti(i,j),nextj(i,j));

    chosen[i][j] = 1;
    ++cnt;
    back(nexti(i,j),nextj(i,j));
    --cnt;
    chosen[i][j] = 0;
}

int solve()
{
    fin >> n >> m >> p;

    ans = inf;
    back(0,0);

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
