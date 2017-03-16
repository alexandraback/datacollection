#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

void tc() {
    int N; cin >> N; vector<int> v(N); for (int i = 0; i < N; ++i) cin >> v[i];

    int vA = 0;
    for (int i = 1; i < N; ++i) vA += max(0, v[i-1]-v[i]);

    int lo = -1, hi = 50000; // (lo, hi]
    while (lo < hi-1) {
        const int mid = (lo + hi) / 2;

        for (int i = 1; i < N; ++i) if (v[i] < v[i-1] - mid) goto infeasible;

feasible: hi = mid; continue;
infeasible: lo = mid; continue;
    }
    int vB = 0;
    for (int i = 0; i < N-1; ++i) vB += min(v[i], hi);

    static int cas = 1; cout << "Case #" << cas++ << ": " << vA << " " << vB << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) tc();
}
