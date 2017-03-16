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

const int NN = 128;

int N, M;
char src[NN][NN];
char G[NN];
int  GC[NN] = {0};
int  SC[NN][NN] = {0};

int calc_idx(int col) {
    int A[NN] = {0};
    F0(i, N) A[i] = SC[i][col];
    int  minVal = *min_element(A, A+N);
    int  maxVal = *max_element(A, A+N);
    int  ans = (maxVal - minVal) * N;
    for(int v=minVal; v<=maxVal; ++v) {
        int cur = 0;
        F0(i, N) cur += abs(A[i] - v);
        ans = min(ans, cur);
    }
    return ans;
}

void calc_c(const char* s, int c[]) {
    int j = 0;
    int n = strlen(s);
    F0(i, M) {
        int k = 0;
        for(; j<n; ++j) if (s[j] == G[i]) ++k; else break;
        c[i] = k;
    }
}


string minimal(const char* s) {
    char t[128];
    t[0] = s[0];
    int  n = 0;
    for(int i=1; s[i]; ++i) {
        if (s[i] != t[n])
            t[++n] = s[i];
    }
    t[++n] = 0;
    return t;
}

int calc() {
    scanf("%d", &N);
    set<string>  U;
    F0(i, N) {
        scanf("%s", src[i]);
        U.insert(minimal(src[i]));
    }
    if (U.size() > 1)
        return -1;
    string dd = *(U.begin());
    M = dd.length();
    F0(i, M) G[i] = dd[i];
    CLR(SC, 0);
    F0(i, N) {
        calc_c(src[i], SC[i]);
    }
    int ret = 0;
    F0(i, M) ret += calc_idx(i);
    return ret;
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    F1(iT, T) {
        int ans = calc();
        printf("Case #%d: ", iT);
        if (ans < 0) {
            printf("Fegla Won\n");
        }
        else
            printf("%d\n", ans);
    }
    return 0;
}
