#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
 
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
 
typedef long long int64;
 
using namespace std;

int solve1(int r, int c, int n) {
    int add = 0;
    int k = (r * c + 1) / 2;
    if (k >= n) return add;
    n -= k;
    int l = 2;
    if (r % 2 == 1 && c % 2 == 1) l = 0;
    if (n <= l) return 2 * n + add;
    add += 2 * l;
    n -= l;
    int m = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if ((i == 0 || j == 0 || i + 1 == r || j + 1 == c) && ((i + j) % 2 == 1))
                ++m;
    m -= l;
    if (n <= m) return 3 * n + add;
    n -= m;
    add += 3 * m;
    return 4 * n + add;
}

int solve2(int r, int c, int n) {
    int add = 0;
    int k = (r * c) / 2;
    if (k >= n) return add;
    n -= k;
    int l = 4;
    if (n <= l) return 2 * n + add;
    add += 2 * l;
    n -= l;
    int m = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if ((i == 0 || j == 0 || i + 1 == r || j + 1 == c) && ((i + j) % 2 == 0))
                ++m;
    m -= l;
    if (n <= m) return 3 * n + add;
    n -= m;
    add += 3 * m;
    return 4 * n + add;
}

void solve() {
    int r, c, n;
    cin >> r >> c >> n;
    if (r > c) swap(r, c);
    if (r == 1 && c % 2 == 0) {
        int k = (c + 1) / 2;
        if (k >= n) {
            cout << "0" << endl;
            return;
        }
        n -= k;
        if (n == 1) {
            cout << "1" << endl;
            return;
        }
        --n;
        cout << 1 + 2 * n << endl;
        return;
    }
    if (r == 1 && c % 2 == 1) {
        int k = (c + 1) / 2;
        if (k >= n) {
            cout << "0" << endl;
            return;
        }
        n -= k;
        cout << 2 * n << endl;
        return;
    }
    
    int answer = solve1(r, c, n);
    if (r % 2 == 1 && c % 2 == 1) answer = min(answer, solve2(r, c, n));
    cout << answer << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
