#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};

inline bool operator < (const Point &a, const Point &b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

inline Point operator - (Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

inline bool operator == (Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

inline long long det(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

const int N = 1e4;

int n;
Point a[N];

inline void solve() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;

    for (int tt = 0; tt < n; ++ tt) {
        vector<pair<double, Point> > pts;
        for (int i = 0; i < n; ++ i)
        	if (i != tt)
				pts.push_back(make_pair(atan2(a[i].y - a[tt].y, a[i].x - a[tt].x), a[i]));
        sort(pts.begin(), pts.end());
        
        vector<Point> p;
        for (int i = 0; i < (int)pts.size(); ++ i)
            p.push_back(pts[i].second);
        for (int i = 0; i < (int)pts.size(); ++ i)
            p.push_back(pts[i].second);

        int ans = 0;
        for (int left = 0, right = 0; left < (int)p.size(); ++ left) {
            for (; right < (int)p.size() && det(p[left] - a[tt], p[right] - a[tt]) >= 0; ++right);
            ans = max(ans, right - left);
        }
        cout << max(n - ans - 1, 0) << endl;
    }
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": " << endl;
		solve();
	}
	return 0;
}

