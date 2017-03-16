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

int  N, A[1024];

int calc2() {
    int  ans = 0;
    for(int i=1; i<N; ++i) {
        ans = std::max(A[i-1] - A[i], ans);
    }
    int ret = 0;
    for(int i=1; i<N; ++i) {
        ret += std::min(A[i-1], ans);
    }
    return ret;
}

int calc1() {
    int  ans = 0;
    for(int i=1; i<N; ++i) {
        ans += std::max(A[i-1] - A[i], 0);
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int T = R();
    F1(iT, T) {
        N = R();
        F0(i, N) A[i] = R();
        printf("Case #%d: %d %d\n", iT, calc1(), calc2());
    }
    return 0;
}
