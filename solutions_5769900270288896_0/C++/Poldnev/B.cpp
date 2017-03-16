#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<long long, long long> plint;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<long long> vlint;
typedef vector<vector<long long>> vvlint;
typedef vector<pair<int, int>> vpint;
typedef vector<pair<long long, long long>> vplint;

ifstream in("B-small-attempt0.in");
ofstream out("B-small-attempt0.out");

int ni(int r, int c, int i, int j) {
    return (j == c - 1) ? i + 1 : i;
}

int nj(int r, int c, int i, int j) {
    return (j == c - 1) ? 0 : j + 1;
}

int go(int r, int c, int n, int i, int j, int res, vector<vector<bool>> &busy) {
    if (i == r) {
        if (n > 0) {
            return 1e9;
        } else {
            return res;
        }
    }

    int best = 1e9;
    for (int x = 0; x <= !!n; ++x) {
        busy[i][j] = x;
        n -= x;
        res += (x && i > 0 && busy[i - 1][j]) + (x && j > 0 && busy[i][j - 1]);
        best = min(best, go(r, c, n, ni(r, c, i, j), nj(r, c, i, j), res, busy));
        res -= (x && i > 0 && busy[i - 1][j]) + (x && j > 0 && busy[i][j - 1]);
        n += x;
        busy[i][j] = false;
    }

    return best;
}

void solve()
{
    int r, c, n;
    in >> r >> c >> n;
    vector<vector<bool>> busy(r, vector<bool>(c, false));
    out << go(r, c, n, 0, 0, 0, busy);
}

int main()
{
    int cases;
    in >> cases;
    for (int z = 0; z < cases; ++z) {
        out << "Case #" << z + 1 << ": ";
        solve();
        out << endl;
    }

    return 0;
}
