#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>
#include <climits>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

#define sqr(x) ((x) * (x))
#define abs(x) (((x) > 0) ? (x) : (-(x))) 
#define lowbit(x) ((x) & (-(x)))

using namespace std;

class Point {
public:
    long long x, y;
    Point(const long long &x = 0, const long long &y = 0) {
        this->x = x;
        this->y = y;
    }
};

inline bool operator < (const Point &a, const Point &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}

inline Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

inline bool operator == (const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

inline long long det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

const int N = 11111;

int n;
Point a[N];

inline void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int pivot = 0; pivot < n; ++pivot) {
        vector<pair<double, Point> > data;
        for (int i = 0; i < n; ++i) {
            if (i == pivot) {
                continue;
            }
            data.push_back(make_pair(atan2(a[i].y - a[pivot].y, a[i].x - a[pivot].x), a[i]));
        }
        sort(data.begin(), data.end());
        
        vector<Point> p;
        for (int i = 0; i < (int)data.size(); ++i) {
            p.push_back(data[i].second);
        }
        for (int i = 0; i < (int)data.size(); ++i) {
            p.push_back(data[i].second);
        }

        int best = 0;
        for (int left = 0, right = 0; left < (int)p.size(); ++left) {
            for (; right < (int)p.size() && det(p[left] - a[pivot], p[right] - a[pivot]) >= 0; ++right);
            best = max(best, right - left);
        }
        cout << max(n - best - 1, 0) << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);

	int tests;
	cin >> tests;
	for (int i = 1; i <= tests; ++i) {
		cout << "Case #" << i << ": " << endl;
		solve();
	}

	return 0;
}
