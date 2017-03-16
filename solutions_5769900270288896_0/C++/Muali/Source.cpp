#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cassert>
#include <queue>
#include <sstream>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair                                                  

int best;
bool desk[20][20];

void clear()
{
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            desk[i][j] = false;
        }
    }
    best = 16 * 1000;
}

void estimate(int r, int c)
{
    int f = 0;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (desk[i][j])
            {
                if (desk[i - 1][j])
                    ++f;
                if (desk[i + 1][j])
                    ++f;
                if (desk[i][j - 1])
                    ++f;
                if (desk[i][j + 1])
                    ++f;
            }
        }
    }
    if (f / 2 < best)
        best = f / 2;
}

void rec(int r, int c, int x, int y, int n)
{
    if (n == 0)
    {
        estimate(r, c);
        return;
    }
    if (x > r)
        return;
    int nx = x;
    int ny = y + 1;
    if (ny > c)
    {
        nx = x + 1;
        ny = 1;
    }
    rec(r, c, nx, ny, n);
    desk[x][y] = true;
    rec(r, c, nx, ny, n - 1);
    desk[x][y] = false;
}

void solve()
{
    clear();
    int r, c, n;
    cin >> r >> c >> n;
    rec(r, c, 1, 1, n);
    cout << best << endl;
}              

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}