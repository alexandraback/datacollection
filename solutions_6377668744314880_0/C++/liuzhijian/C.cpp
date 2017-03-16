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

const int N = 22;

int n;
Point a[N];

inline long long det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

inline long long det(const vector<Point> &stack, const Point &p) {
    Point a = stack[(int)stack.size() - 2];
    Point b = stack[(int)stack.size() - 1];
    return det(p - a, p - b);
}

inline vector<Point> convex_hull(vector<Point> p) {
    vector<Point> result;
    sort(p.begin(), p.end());

    {
        vector<Point> stack;
        for (int i = 0; i < (int)p.size(); ++i) {
            for (; (int)stack.size() >= 2 && det(stack, p[i]) > 0; stack.pop_back());
            stack.push_back(p[i]);
        }
        for (int i = 0; i < (int)stack.size(); ++i) {
            result.push_back(stack[i]);
        }
    }
    {
        vector<Point> stack;
        for (int i = (int)p.size() - 1; i >= 0; --i) {
            for (; (int)stack.size() >= 2 && det(stack, p[i]) > 0; stack.pop_back());
            stack.push_back(p[i]);
        }
        for (int i = 0; i < (int)stack.size(); ++i) {
            result.push_back(stack[i]);
        }
    }

    return result;
}

inline void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int pivot = 0; pivot < n; ++pivot) {
        int best = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (~mask >> pivot & 1) {
                continue;
            }
            vector<Point> candidate;
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    candidate.push_back(a[i]);
                }
            }
            vector<Point> convex = convex_hull(candidate);
            for (int i = 0; i < (int)convex.size(); ++i) {
                if (convex[i] == a[pivot]) {
                    best = max(best, __builtin_popcount(mask));
                    break;
                }
            }
        }
        cout << n - best << endl;
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
