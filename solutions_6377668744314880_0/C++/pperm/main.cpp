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
#include <thread>

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

struct Point {
    i64 x, y;

    Point(i64 x = 0, i64 y = 0) : x(x), y(y) { }

    Point rot() const{
        return Point(-y, x);
    }

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    i64 operator&(const Point &p) const {
        return x * p.x + y * p.y;
    }
};

struct Solver {
    vector<Point> p;
    VI res;
    thread t;

    void solve(vector<Point> a) {
        this->p = a;
        t = thread(&Solver::run, this);
    }

    void run() {
        int n = p.size();
        res.resize(n, n - 1);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                Point a = (p[i] - p[j]).rot();
                i64 d = (a & p[i]);
                int down = 0;
                int up = 0;
                for (const Point &cp : p) {
                    i64 cur = (a & cp);
                    if (cur < d) {
                        down++;
                    } else if (cur > d) {
                        up++;
                    }
                }
                int cur = min(up, down);
                res[i] = min(res[i], cur);
                res[j] = min(res[j], cur);
            }
        }
    }
};

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
    vector<Solver> res(T);
    for (int iTest = 1; iTest <= T; ++iTest) {
        int n;
        cin >> n;
        vector<Point> a(n);
        for (Point &p : a) {
            cin >> p.x >> p.y;
        }
        res[iTest - 1].solve(a);
    }
    for (Solver &s : res) {
        s.t.join();
    }
    for (int i = 0; i < T; i++) {
        cout << "Case #" << (i + 1) << ":" << endl;
        Solver &s = res[i];
        for (int x : s.res) {
            cout << x << endl;
        }
    }
#ifdef pperm
    flush(cout);
    cerr << endl << "Time: " << (clock() / double(CLOCKS_PER_SEC)) << endl;
#endif
    return 0;
}
