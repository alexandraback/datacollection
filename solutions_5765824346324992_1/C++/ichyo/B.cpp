// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

class range {
    struct Iterator {
        int val, inc;
        int operator*() {return val;}
        bool operator!=(Iterator& rhs) {return val < rhs.val;}
        void operator++() {val += inc;}
    };
    Iterator i, n;
    public:
    range(int e) : i({0, 1}), n({e, 1}) {}
    range(int b, int e) : i({b, 1}), n({e, 1}) {}
    range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
    Iterator& begin() {return i;}
    Iterator& end() {return n;}
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}
int solve() {
    int B;
    LL N;
    cin >> B >> N;

    vector<int> M(B);
    REP(i, B) cin >> M[i];

    if(N <= B) {
        return N;
    }

    LL lb = 0, ub = 1e14+10;
    while(ub - lb > 1) {
        LL t = (lb + ub) / 2;
        
        LL sum = 0;
        REP(i, B) {
            sum += (t / M[i]) + 1;
            if(sum > N) break;
        }
        if(sum < N) {
            lb = t;
        } else {
            ub = t;
        }
    }

    LL sum = 0;
    REP(i, B) {
        sum += (lb / M[i]) + 1;
    }

    int ans = -1;

    LL T = ub;
    REP(i, B) {
        if(T % M[i] == 0) {
            if(++sum == N) {
                ans = i;
                break;
            }
        }
    }

    assert(ans != -1);
    return ans + 1;
}
int main(){
    iostream_init();
    int TEST_CASE; cin >> TEST_CASE;
    for(int i = 1; i <= TEST_CASE; i++){
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}

/* vim:set foldmethod=marker: */

