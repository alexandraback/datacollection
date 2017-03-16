#include <bits/stdc++.h>
using namespace std;

#ifdef ILIKEGENTOO
#   define Eo(x) { cerr << #x << " = " << (x) << endl; }
#   define E(x) { cerr << #x << " = " << (x) << "   "; }
#   define FREOPEN(x)
#else
#   define Eo(x) {}
#   define E(x) {}
#   define FREOPEN(x) (void)freopen(x ".in", "r", stdin);(void)freopen(x ".out", "w", stdout);
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<class A, class B> ostream &operator<<(ostream &os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<class C> void operator<<(vector<C> &v, const C &x){v.push_back(x);}
template<class D> void operator>>(vector<D> &v, D &x){assert(!v.empty()); x=v.back(); v.pop_back();}
template<class E> void operator<<(set<E> &v, const E &x){v.insert(x);}

typedef double flt;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-8;
const flt pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

random_device rdev; mt19937 rmt(rdev()); uniform_int_distribution<> rnd(0, 0x7fffffff);
inline int mrand(int mod = 0x7fffffff) { return rnd(rmt) % mod; }

inline int bit(int t) { return 1 << t; }

bool field[30][30];
int solveSlow(int r, int c, int n) {
    int rc = r * c;
    assert(rc <= 30);
    int best = inf;
    for (int i = 0; i < bit(rc); ++i) {
        if (__builtin_popcount(i) != n) continue;
        for (int j = 0; j < rc; ++j)
            field[j/c][j%c] = i & bit(j);
        int cur = 0;
        for (int j = 0; j < r; ++j) for (int k = 0; k < c; ++k) if (field[j][k]) for (int d = 0; d < 2; ++d) {
            int nj = j + dir[d][0];
            int nk = k + dir[d][1];
            if (nj >= r || nk >= c) continue;
            if (field[nj][nk]) {
                ++cur;
            }
        }
        if (cur <= best) {
            best = cur;
#if 0
            cout << cur << endl;
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) printf("%d", field[j][k] ? 1 : 0);
                puts("");
            }
            puts("");
#endif
        }
    }
    return best;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        int r, c, n; cin >> r >> c >> n;
        int res = solveSlow(r, c, n);
        cout << "Case #" << test << ": " << res << endl;
    }

    return 0;
}
