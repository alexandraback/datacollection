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

int inf = 1000000000;

void solve() {
    int r, c, n;
    cin >> r >> c >> n;
    int answer = inf;
    for (int i = 0; i < (1 << (r * c)); ++i) {
        int cnt = 0;
        vector<vector<int> > a(r, vector<int> (c, 0));
        for (int j = 0; j < r * c; ++j) {
            if (i & (1 << j)) {
                a[j / c][j % c] = 1;
                ++cnt;
            }
        }
        if (cnt != n) continue;
        int result = 0;
        for (int j = 0; j < r; ++j)
            for (int k = 0; k + 1 < c; ++k)
                if (a[j][k] == 1 && a[j][k + 1] == 1)
                    ++result;
        for (int j = 0; j + 1 < r; ++j)
            for (int k = 0; k < c; ++k)
                if (a[j][k] == 1 && a[j + 1][k] == 1)
                    ++result;
        answer = min(answer, result);
    }
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
