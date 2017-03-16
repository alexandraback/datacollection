#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cassert>
#include <complex>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef int z;
#define int ll

typedef complex<int> P;
typedef complex<double> Q;

inline int dot(P a, P b) { return real(conj(a)*b); }
inline int cross(P a, P b) { return imag(conj(a)*b); }
Q tod(P a) { return Q(a.real(), a.imag()); }

void tc() {
    int N; cin >> N;
    vector<P> p;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        p.push_back(P(x, y));
    }

    static int cas = 1;
    cout << "Case #" << cas++ << ":" << '\n';
    vector<int> best(N, N-1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) if (j!=i) {
            int n = 0;
            for (int k = 0; k < N; ++k) {
                if (cross(p[k]-p[i],p[j]-p[i]) < 0) ++n;
            }
            best[i] = min(best[i], n);
            best[j] = min(best[j], n);
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << best[i] << endl;
    }
}
z main() {
    int T;
    cin >> T;
    while (T--) tc();
}
