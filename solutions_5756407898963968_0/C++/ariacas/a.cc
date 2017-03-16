#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        int r;
        vvi v(4, vi(4));
        cin >> r;
        --r;
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j)
            cin >> v[i][j];
        vi cur = v[r];
        sort(cur.begin(), cur.end());
        cin >> r;
        --r;
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j)
            cin >> v[i][j];
        int cnt = 0, ans = 0;
        for (int i = 0; i < 4; ++i) {
            if (binary_search(cur.begin(), cur.end(), v[r][i])) {
                ++cnt;
                ans = v[r][i];
            }
        }
        if (cnt == 0) {
            printf("Volunteer cheated!\n");
        } else if (cnt > 1) {
            printf("Bad magician!\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
