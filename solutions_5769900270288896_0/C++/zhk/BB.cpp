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

char W[1<<16];

int zz(int k, int R, int C, int mask) {
    int ans = 0;
    int r = k / C;
    int c = k % C;
    int k2 = 0;
    if (r + 1 < R && ((1<<((r+1)*C + c)) & mask)) ++ans;
    if (c + 1 < C && ((1<<(r*C + c + 1)) & mask)) ++ans;
    return ans;
}

int calc() {
    int r = R();
    int c = R();
    int n = R();
    int m = r * c;
    int bitEnd = 1<<m;
    std::fill(W, W+bitEnd, '\0');
    int ans = (r-1)*c + (c - 1) * r;
    F0(bit, bitEnd) {
        int cc = 0;
        F0(i, m) cc += (bit>>i) & 1;
        if (cc != n) continue;
        cc = 0;
        F0(i, m) if ((bit>>i) & 1)  cc += zz(i, r, c, bit);
        cMin(ans, cc);
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int T = R();
    F1(iT, T) {
        printf("Case #%d: %d\n", iT, calc());
    }
    return 0;
}
