#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <list>
#include <stdio.h>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024,
    boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void> > uint1024_t;
typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024,
    boost::multiprecision::signed_magnitude, boost::multiprecision::unchecked, void> > int1024_t;
typedef uint1024_t ulll;       // 10^300
typedef int1024_t lll;         // 10^150
#endif

typedef unsigned __int64 ull;  // 10^18
typedef __int64 ll;            // 10^19

using namespace std;

int T;

int cntbit(int i) {
    int res = 0;
    while (i > 0) {
        if (i & 1) res++;
        i = (i >> 1);
    }
    return res;
}

int unhap(int i, int R, int C) {
    int res = 0;
    int mask = (1 << C)-1;
    for (int x = 0; x < R; ++x) {
        int row = (i >> (C * x)) & mask;
        while (row > 0) {
            if ((row & 3) == 3) res++;
            row = (row >> 1);
        }
    }
    for (int x = 0; x < R - 1; ++x) {
        int row1 = (i >> (C * x)) & mask;
        int row2 = (i >> (C * (x+1))) & mask;
        res += cntbit(row1 & row2);
    }
    return res;
}

int solve() {
    int R, C, N;
    cin >> R >> C >> N;
    int RC = R * C;
    int mask = (1 << (R*C)) - 1;
    int a = (R-1)*C + (C-1)*R;
    for (int i = 0; i <= mask; ++i) {
        if (cntbit(i) == N) {
            a = min(a, unhap(i, R, C));
        }
    }
    return a;
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t != T; ++t) {
        int s = solve();
        if (s == -1)
            printf("Case #%d: I don't know.\n", t + 1);
        else
            printf("Case #%d: %d\n", t + 1, s);
    }
    return 0;
}
