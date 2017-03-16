#pragma comment(linker, "/STACK:500000000")
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <set>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdint.h>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <queue>
#include <functional>

#pragma warning(disable : 4996)

using namespace std;
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007ull
#define INF 999999999
#define SPLIT 1000000000

bool a[17][17];

int c_unhappy(int r, int c)
{
    int ans = 0;
    for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
    {
        if (!a[i][j])
            continue;
        if (i > 0 && a[i - 1][j])
            ans++;
        if (i < r - 1 && a[i + 1][j])
            ans++;
        if (j > 0 && a[i][j - 1])
            ans++;
        if (j < c - 1 && a[i][j + 1])
            ans++;
    }
    return ans;
}

int m;

vector<pair<int, int > > b;

void backtrack(int r, int c, int x, int y, int n)
{
    if (b.size() == n)
    {
        m = min(m, c_unhappy(r, c));
        return;
    }
    while (y != c)
    {
        int next_x = (x == r - 1) ? 0 : x + 1;
        int next_y = (x == r - 1) ? y + 1 : y;
        b.push_back(make_pair(x, y));
        a[x][y] = true;
        backtrack(r, c, next_x, next_y, n);
        a[x][y] = false;
        b.pop_back();
        x = next_x;
        y = next_y;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int k = 0; k < T; k++)
    {
        int r, c, n;
        cin >> r >> c >> n;
        m = INF;
        backtrack(r, c, 0, 0, n);
        cout << "Case #" << k + 1 << ": " << m / 2 << endl;
    }
    //system("PAUSE");
    return 0;
}