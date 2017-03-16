#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

bool m[20][20];

void mask_to_map(int mask, int r, int c) {
    forn(i, r*c) {
        bool val = ((mask & (1 << i)) != 0);

        m[i/c][i%c] = val;
    }
}

int count_walls(int r, int c) {
    int res = 0;

    forn(i, r) {
        forn(j, c) {
            if(m[i][j] && m[i][j+1]) {
                ++res;
            }

            if(m[i][j] && m[i+1][j]) {
                ++res;
            }
        }
    }

    return res;
}

int solve() {
    memset(m, 0, sizeof(m));

    int r, c, n;
    cin >> r >> c>> n;

    int ans = INT32_MAX;
    for(int mask = 0; mask < (1<<(r*c)); ++mask) {
        if(__builtin_popcount(mask) == n) {
            mask_to_map(mask, r, c);
            ans = min(ans, count_walls(r, c));
        }
    }

    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    forn(tc, T) {
        auto res = solve();

        std::cout << "Case #" << tc + 1 << ": " << res << endl;
    }
    
    return 0;
}
