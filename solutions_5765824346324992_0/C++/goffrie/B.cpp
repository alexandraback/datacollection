#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long ll;
typedef int z;
#define int ll

vector<int> barbers;

int started(int t) {
    int r = 0;
    for (int b : barbers) {
        r += t / b + 1;
    }
    return r;
}

void tc() {
    int B, T;
    cin >> B >> T;
    barbers.assign(B, 0); for (int& x: barbers) cin >> x;
    int lo = -1, hi = 1000000000000000000ll; // started(lo) < T; started(hi) >= T
    while (lo < hi - 1) {
        int mid = (lo + hi) / 2;
        if (started(mid) < T) lo = mid;
        else hi = mid;
    }
    int ix = started(hi) - T;
    cerr << lo << ',' << hi << ',' << started(hi) << ":" << ix << endl;
    assert(ix >= 0);
    static int cas = 0; ++cas;
    for (int i = B; i--; ) { int b = barbers[i];
        if (hi % b == 0) {
            if (!ix--) {
                cout << "Case #" << cas << ": " << (i+1) << endl;
                return;
            }
        }
    }
    assert(0);
}

z main() {
    int T;
    cin >> T;
    while (T--) tc();
}
