/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int t, row, col, n;

int count_walls(int flag) {
    if (row > col)
        swap(row, col);
    if (row == 1) {
        int m = n - (col + 1) / 2;
        if (m <= 0)
            return 0;
        return col % 2 == 0 ? 1 + (m - 1) * 2 : m * 2;
    }
    vector<vector<bool> > grid(row, vector<bool>(col));
    int cnt = 0;
    for (int i = 0; i < row && cnt < n; ++i) {
        for (int j = 0; j < col && cnt < n; ++j) {
            if ((i + j) % 2 == flag) {
                grid[i][j] = true;
                ++cnt;
            }
        }
    }
    int res = 0;
    if (!grid[0][0] && cnt < n) {
        grid[0][0] = true;
        ++cnt;
        res += 2;
    }
    if (!grid[0][col - 1] && cnt < n) {
        grid[0][col - 1] = true;
        ++cnt;
        res += 2;
    }
    if (!grid[row - 1][0] && cnt < n) {
        grid[row - 1][0] = true;
        ++cnt;
        res += 2;
    }
    if (!grid[row - 1][col - 1] && cnt < n) {
        grid[row - 1][col - 1] = true;
        ++cnt;
        res += 2;
    }
    for (int i = 0; i < row && cnt < n; ++i) {
        if (!grid[i][0]) {
            grid[i][0] = true;
            ++cnt;
            res += 3;
        }
    }
    for (int i = 0; i < row && cnt < n; ++i) {
        if (!grid[i][col - 1]) {
            grid[i][col - 1] = true;
            ++cnt;
            res += 3;
        }
    }
    for (int j = 0; j < col && cnt < n; ++j) {
        if (!grid[0][j]) {
            grid[0][j] = true;
            ++cnt;
            res += 3;
        }
    }
    for (int j = 0; j < col && cnt < n; ++j) {
        if (!grid[row - 1][j]) {
            grid[row - 1][j] = true;
            ++cnt;
            res += 3;
        }
    }
    for (int i = 0; i < row && cnt < n; ++i) {
        for (int j = 0; j < col && cnt < n; ++j) {
            if ((i + j) % 2 != flag && !grid[i][j]) {
                grid[i][j] = true;
                ++cnt;
                res += 4;
            }
        }
    }
    return res;
}

void solve() {
    scanf("%d%d%d", &row, &col, &n);
    printf("Case #%d: %d\n", ++t, min(count_walls(0), count_walls(1)));
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
