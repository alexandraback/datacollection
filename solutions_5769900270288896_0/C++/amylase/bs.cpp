#include <bits/stdc++.h>
using namespace std;

typedef long long li;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

struct problem {
    // input fields.
    int r, c, n, ans;
    
    // parse here.
    problem () {
        cin >> r >> c >> n;
    }

    int getpos(int x, int y) {
        return x * c + y;
    }

    bool exist(int x, int y, int mask) {
        return mask & (1 << getpos(x, y));
    }

    // called exactly once. set ans here.
    void solve () {
        const int area = r * c;
        const int pattern = 1 << area;
        ans = r * (c - 1) + (r - 1) * c;
        rep(mask, pattern) {
            if (__builtin_popcount(mask) != n) continue;
            int tans = 0;
            rep(x, r) rep(y, c - 1) {
                if (exist(x, y, mask) && exist(x, y + 1, mask)) {
                    tans++;
                }
            }
            rep(x, r - 1) rep(y, c) {
                if (exist(x, y, mask) && exist(x + 1, y, mask)) {
                    tans++;
                }
            }
                
            ans = min(ans, tans);
        }
    }
};

// generally you don't have to modify below.
int main () {
    int t;
    cin >> t;
    vector<problem> inputs;
    rep (i, t) {
        inputs.push_back(problem());
    }
    #pragma omp parallel for
    rep (i, t) {
        inputs[i].solve();
    }
    rep (i, t) {
        cout << "Case #" << i + 1 << ": " << inputs[i].ans << endl;
    }
    return 0;
}
