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
#include <numeric>
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


int N;
int src[32];

void solve() {
    typedef std::pair<int, int> PII;
    int sum = accumulate(src, src+N, 0);
    std::priority_queue<PII> Q;
    F0(i, N) Q.push(PII(src[i], i));
    while(sum > 0) {
        PII a = Q.top(); Q.pop();
        PII b = Q.top(); Q.pop();
        if (b.first * 2 <= sum - 1) {
            printf(" %c", 'A' + a.second);
            Q.push(b); a.first -= 1;
            if (a.first > 0) Q.push(a);
            sum -= 1;
        }
        else if ((a.first - 1) * 2 <= sum - 2) {
            printf(" %c%c", 'A' + a.second, 'A' + b.second);
            a.first -= 1;
            b.first -= 1;
            if (a.first > 0) Q.push(a);
            if (b.first > 0) Q.push(b);
            sum -= 2;
        } else if (a.first > 1 && b.first * 2 <= sum - 2) {
            printf(" %c%c", 'A' + a.second, 'A' + a.second);
            a.first -= 2;
            if (a.first > 0) Q.push(a);
            if (b.first > 0) Q.push(b);
            sum -= 2;
        } else {
            throw std::runtime_error("invalid");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int T;scanf("%d", &T);
    F1(Ti, T) {
        scanf("%d", &N);
        F0(i, N) scanf("%d", src+i);
        printf("Case #%d:", Ti);
        solve();
    }
    return 0;
}
