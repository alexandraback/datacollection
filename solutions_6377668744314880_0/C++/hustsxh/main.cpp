#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long LL;


struct Point {
    LL x, y;
    Point(LL x = 0, LL y = 0) : x(x), y(y) {}
    Point operator-(const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    LL cross(const Point &b) const {
        return y * b.x - x * b.y;
    }
    bool operator <(const Point &b) const {
        return cross(b) < 0;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    // sort(points.begin(), points.end());
    // for (int i = 0; i < n; ++i) cout << points[i].x << " " << points[i].y << endl;
    
    vector<Point> ps(n - 1);
    for (int k = 0; k < n; ++k) {
        ps.resize(0);
        for (int i = 0; i < n; ++i) {
            if (i != k) ps.push_back(points[i] - points[k]);
        }
        sort(ps.begin(), ps.end());
        size_t result = ps.size();
        // cout << "k = " << k << endl;
        for (size_t p = 0, q = 1; p < ps.size(); ++p) {
            while (p != q && ps[p].cross(ps[q]) <= 0) q = (q + 1) % ps.size();
            // cout << "p, q = " << p << ", " << q << endl;
            result = min(result, min((p - q + ps.size()) % ps.size(),
                                     (q - p + ps.size()) % ps.size()));
        }
        cout << result << endl;
    }
}

int main() {
    int testcase;
    freopen("/Volumes/Data/download/C-small-attempt1.in", "r", stdin);
    freopen("/Volumes/Data/download/out.txt", "w", stdout);

    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": " << endl;
        solve();
    }
    return 0;
}
