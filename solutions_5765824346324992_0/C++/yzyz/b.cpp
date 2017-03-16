#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#include <cassert>
#define MAXB 1010
#define INF 1000000000000000000ll

using namespace std;

long long b,n,m[MAXB];

long long ct(long long t) {
    long long res = 0;
    for (int i = 1; i <= b; i++)
        res += (t + m[i] - 1) / m[i];
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> b >> n;
        for (int i = 1; i <= b; i++) cin >> m[i];
        long long lo = 0, hi = INF, mid;
        while (hi - lo > 1) {
            mid = (lo + hi) / 2;
            if (ct(mid) < n) lo = mid;
            else hi = mid;
        }
        long long x = ct(lo);
        int ans = 1;
        for (; ans <= b && x < n; ans++) {
            if (lo % m[ans] == 0) x++;
            if (x == n) break;
        }
        cerr << TC << endl;
        assert(ans <= b);
        cout << "Case #" << TC << ": ";
        cout << ans << '\n';
    }
}
