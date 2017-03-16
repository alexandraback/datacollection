#include <bits/stdc++.h>

using namespace std;

int dfs(bool g[16][16], int r, int c, int i, int j, int n)
{
    int u = INT_MAX;
    if (i == r * c)
    {
        u = 0;
        for (int k = 0; k < r; k++)
        {
            for (int l = 0; l < c; l++)
            {
                if (!g[k][l])
                    continue;
                if (k < r - 1 && g[k + 1][l])
                    u++;
                if (l < c - 1 && g[k][l + 1])
                    u++;
            }
        }
        return u;
    }
    g[i / c][i % c] = false;
    if (r * c - i + j > n)
        u = min(u, dfs(g, r, c, i + 1, j, n));
    g[i / c][i % c] = true;
    if (j < n)
        u = min(u, dfs(g, r, c, i + 1, j + 1, n));
    return u;
}

void solve_case(ifstream &fin, ofstream &fout)
{
    int r, c, n;
    fin >> r >> c >> n;
    bool g[16][16];
    fout << dfs(g, r, c, 0, 0, n) << endl;
}


int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name)-2] = 0;
    strcat(name, "out");
    ofstream fout(name);

    if (!fin.is_open() || !fout.is_open())
        return 1;

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t) {
        cerr << "Solving case " << t1 << endl;
        fout << "Case #" << t1 << ": ";
        solve_case(fin, fout);
    }

    return 0;
}