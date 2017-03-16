#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }


#define x1 xx1
#define y1 yy1
#define x2 xx2
#define y2 yy2


inline LL Vm(LL x1, LL y1, LL x2, LL y2) {
    return x1 * y2 - x2 * y1;
}


void Solution() {
    int n;
    cin >> n;
    vector<LL> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    cout << endl;
    for (int i = 0; i < n; ++i) {
        int best = n - 1;
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }
            int minus = 0;
            int plus = 0;
            for (int k = 0; k < n; ++k) {
                LL vm = Vm(x[k]-x[i],y[k]-y[i],x[j]-x[i],y[j]-y[i]);
                if (vm < 0) {
                    minus += 1;
                } else {
                    plus += 1;
                }
            }
            if (best > min(minus, plus)) {
                best = min(minus, plus);
            }
        }
        cout << best << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        float startTime = clock() / CLOCKS_PER_SEC;
        cout << "Case #" << i + 1 << ": ";
        Solution();
        float endTime = clock() / CLOCKS_PER_SEC;
        cerr << "Test #" << i + 1 << ": elapsed time is " << endTime - startTime;
        cerr << endl;
    }

    return 0;
}


