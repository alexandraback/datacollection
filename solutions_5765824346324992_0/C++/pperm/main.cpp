#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <sstream>
#include <exception>
#include <cassert>

typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
using namespace std;

typedef vector<int> VI;

#define all(a) a.begin(),a.end()

template<class T>
int size(const T &a) {
    return int(a.size());
}

template<class T>
T abs(const T &a) {
    return (a < 0 ? -a : a);
}

template<class T>
T sqr(const T &a) {
    return a * a;
}

const double pi = acos(-1.0);

int mod = int(1e9 + 7.1);

inline int msum(int a, int b) {
    return (a + b < mod ? a + b : a + b - mod);
}

inline int mdiff(int a, int b) {
    return (a < b ? a - b + mod : a - b);
}

inline void madd(int &a, int b) {
    a = msum(a, b);
}

inline void msub(int &a, int b) {
    a = mdiff(a, b);
}

inline i64 mmul(int a, int b) {
    return i64(a) * b % mod;
}

struct Line {
    int k, b;

    Line(int k = 0, int b = 0) : k(k), b(b) { }
};

i64 sum(i64 a0, i64 d, i64 n) {
    return (a0 + d * (n - 1)) * n / 2;
}

int main() {
#ifdef pperm
    freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int iTest = 1; iTest <= T; ++iTest) {
        int n;
        int m;
        cin >> m >> n;
        VI a(m);
        for (int &x : a) {
            cin >> x;
        }
        i64 d = 0, u = 100000L * n;
        i64 time = -1;
        while (d <= u) {
            i64 mid = (d + u) >> 1;
            i64 served = 0;
            for (int x : a) {
               served += mid / x + 1;
            }
            if (served < n) {
                d = mid + 1;
            } else {
                time = mid;
                u = mid - 1;
            }
        }
        VI b;
        for (int i = 0; i < m; ++i) {
            int x = a[i];
            n -= time / x;
            if (time % x == 0) {
                b.push_back(i + 1);
            } else {
                n--;
            }
        }
        sort(all(b));
        cout << "Case #" << iTest << ": " << b[n - 1] << endl;
    }

#ifdef pperm
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif
    return 0;
}
