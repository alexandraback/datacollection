#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cassert>
#include <climits>
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
    for (int i = 0; i < N; ++i) {
        if (N <= 2) {
            cout << 0 << endl; continue;
        }
        P me = p[i];
        vector<pair<double, P> > pp;
        for (int j = 0; j < N; ++j) if (j!=i) {
            P q = p[j]-me;
            pp.push_back(make_pair(arg(tod(q)), q));
        }
        sort(pp.begin(), pp.end(), [&](const auto& a, const auto& b) {
            P da = a.second, db = b.second;
            if (cross(da, db) == 0 && dot(da, db) > 0) {
                assert(a.first == b.first);
                return norm(da) < norm(db);
            }
            assert(a.first != b.first);
            return a.first < b.first;
        });
        // for (auto&& x: pp) cerr << x.second << ' ';
        // cerr << endl;
        // cerr << cross(pp[0].second - me, pp[1].second - me) << endl;
        int best = INT_MAX;
        for (int j = 0; j < pp.size(); ++j) {
#define CCW(k) (cross(pp[j].second, pp[(j+(k))%pp.size()].second))
#define DOTCCW(k) (dot(pp[j].second, pp[(j+(k))%pp.size()].second))
            // for (int k = 1; k <= pp.size(); ++k) cerr << CCW(k) << ' ';
            // cerr << endl;
            int next = CCW(1);
            if (next < 0 || (next == 0 && (DOTCCW(1) < 0 || norm(pp[(j+1)%pp.size()].second) < norm(pp[j].second)))) {
                best = 0; break;
            }
            if (next == 0) continue;
            int lo = 1, hi = pp.size();
            assert(CCW(lo) > 0);
            assert(CCW(hi) <= 0);
            while (lo < hi - 1) {
                int mid = (lo + hi) / 2;
                if (CCW(mid) > 0) lo = mid;
                else hi = mid;
            }
            assert(CCW(lo) > 0);
            assert(CCW(hi) <= 0);
            best = min(best, lo);
        }
        for (int j = 0; false&&j < pp.size(); ++j) {
#define CW(k) (cross(pp[j].second, pp[(j+pp.size()-(k))%pp.size()].second))
#define DOTCW(k) (dot(pp[j].second, pp[(j+pp.size()-(k))%pp.size()].second))
            // for (int k = 1; k <= pp.size(); ++k) cerr << CW(k) << ' ';
            // cerr << endl;
            int next = CW(1);
            if (next > 0 || (next == 0 && DOTCW(1) < 0)) {
                best = 0; break;
            }
            if (next == 0) continue;
            int lo = 1, hi = pp.size();
            assert(CW(lo) < 0);
            assert(CW(hi) >= 0);
            while (lo < hi - 1) {
                int mid = (lo + hi) / 2;
                if (CW(mid) < 0) lo = mid;
                else hi = mid;
            }
            assert(CW(lo) < 0);
            assert(CW(hi) >= 0);
            best = min(best, lo);
        }
        cout << best << endl;
    }
}
z main() {
    int T;
    cin >> T;
    while (T--) tc();
}
