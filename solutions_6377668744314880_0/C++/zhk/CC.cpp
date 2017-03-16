#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>inline string to_str(const T& v) {
    ostringstream os; os << v; return os.str();
}
template<typename T>inline T to_obj(const string& v) {
    istringstream is(v); T r; is>>r; return r;
}
template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}

#define CLR(A,v) memset(A, v, sizeof(A))
#define MP(a,b)  make_pair(a, b)
#define F0(i, n) for(int i=0; i<(n); ++i)
#define F1(i, n) for(int i=1; i<=(n); ++i)

inline int R() {int v; scanf("%d", &v); return v;}
typedef std::pair<int, int> PII;
typedef long long i64;

inline i64 ccw(PII a, PII b) {
    return a.first * (i64)(b.second) - a.second* (i64)(b.first);
}

i64 dot(PII a, PII b) {
    return a.first * (i64)(b.first) + a.second* (i64)(b.second);
}

bool cmp(const PII& a, const PII& b) {
    return ccw(a, b) > 0;
}

int qIdx(PII a) {
    if(a.first >= 0) return a.second >= 0 ? 0 : 3;
    return a.second >= 0 ? 1 : 2;
}
int same(PII a, PII b) {
    return qIdx(a) == qIdx(b);
}

int N, srcX[3008], srcY[3008];

int calc(int center) {
    if (N <= 3) return 0;
    typedef std::vector<PII> VPII;
    VPII A;
    // A.reserve(N-1);
    F0(i, N) if(i != center) {
        A.push_back(MP(srcX[i]-srcX[center], srcY[i] - srcY[center]));
    }
    std::sort(A.begin(), A.end(), cmp);
    int  M = N - 1;
    int  S=0, T=1;
    int  ans = M;
    for(; S<M;) {
        int SCnt = 1;
        int  k = 1, _s = S++;
        for(; k<M && S<M; ++k) {
            if(same(A[_s], A[S]) && ccw(A[_s], A[S]) == 0) {
                // printf("%d,%d %d,%d\n", A[_s].first, A[_s].second,
                //        A[S].first, A[S].second);
                ++S;
                continue;
            }
            break;
        }
        SCnt = S - _s;
        if (T <= S && T >= _s) T = S%M;
        for(; k<M && T!=_s; ++k) {
            if(!same(A[_s], A[T])) break;
            T = (T+1)%M;
        }
        for(; k<M && T!=_s; ++k) {
            // printf("%d:%d,%d  --> %d:%d,%d\n", _s, A[_s].first, A[_s].second,
            //        T, A[T].first, A[T].second);
            if (ccw(A[_s], A[T]) <= 0) break;
            T = (T+1)%M;
        }
        if (T == _s) return 0;
        int cnt = (T!=_s ? 1 : 0);
        int _t = (T+1) % M;
        for(; k<M && T!=_s && _t != _s; ++k) {
            if (same(A[T], A[_t]) && ccw(A[T], A[_t]) == 0) {
                ++cnt;
                _t = (_t+1) % M;
                continue;
            }break;
        }
        if (_t == _s) return 0;
        int  cc = 0;
        if (T >= S) cc = T - S;
        else cc = T + M - S;
        // printf("cc = %d   S=%d _s=%d  T=%d _t=%d SCnt=%d cnt=%d\n", cc, S,
        //        _s, T, _t, SCnt, cnt);
        ans = std::min(ans, cc);
        if (_t > _s) cc = _s + M - _t;
        else cc = _s - _t;
        ans = std::min(ans, cc);
        // ans = std::min(ans, M - cc - cnt - SCnt);
        T = (_t + M - 1) % M;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int T = R();
    F1(iT, T) {
        N = R();
        F0(i, N) {
            srcX[i] = R();
            srcY[i] = R();
        }
        printf("Case #%d:\n", iT);
        F0(i, N) {
            printf("%d\n", calc(i));
        }
    }
    return 0;
}
