// ================================================================================================
//  C.cpp
//  Written by Luis Garcia, 2015
// ================================================================================================

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <iostream>

using namespace std;

#if defined _OJ_PROJECT
_BEGIN_PROBLEM(_GCJ15_02C, "GCJ15 02C")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

struct Point {
	long long x, y;
    int id;
};

inline bool CCW(const Point & a, const Point & b, const Point & c) {
	return (c.y - a.y) * (b.x - a.x) < (c.x - a.x) * (b.y - a.y);
}

int GrahamScan(Point * pts, int * out, int count, int removed) {
	int upperhull_size = 0, * upperhull = out;
    for (int i = 0; i < count; ++i) {
        if ((1 << i) & removed) continue;
        while (upperhull_size >= 2 && CCW(pts[i], pts[upperhull[upperhull_size - 2]], pts[upperhull[upperhull_size - 1]]))
            --upperhull_size;
		upperhull[upperhull_size++] = i;
    }

	int lowerhull_size = 1, * lowerhull = upperhull + upperhull_size - 1;
    for (int i = count - 2; i >= 0; --i) {
        if ((1 << i) & removed) continue;
        while (lowerhull_size >= 2 && CCW(pts[i], pts[lowerhull[lowerhull_size - 2]], pts[lowerhull[lowerhull_size - 1]]))
            --lowerhull_size;
		lowerhull[lowerhull_size++] = i;
    }

    return upperhull_size + lowerhull_size - 2;
}

int main() {
    Point pts[100];
    int hull[100];

    int T, N;
    cin >> T;

    for (int _T = 1; _T <= T; ++_T) {
        cin >> N;

        for (int i = 0; i < N; ++i) {
            cin >> pts[i].x >> pts[i].y;
            pts[i].id = i;
        }

        sort(pts, pts + N, [](const Point & left, const Point & right) {
	        if (left.x != right.x) return left.x < right.x;
	        return left.y < right.y;
        });

        vector<int> ans(N, 1000);
        for (int i = 0; i < N; ++i) {
            for (int t = 0; t < (1 << N); ++t) {
                if (t & (1 << i)) continue;

                int removed = 0;
                for (int r = t; r > 0; r >>= 1) removed += (r & 1);
                if (N - removed < 3) continue;

                int k = GrahamScan(pts, hull, N, t);
                if (find(hull, hull + k, i) != hull + k) ans[pts[i].id] = min(ans[pts[i].id], removed);
            }
        }

        cout << "Case #" << _T << ":" << endl;
        for (int i = 0; i < N; ++i) cout << (N >= 3 ? ans[i] : 0) << endl;
    }

    return 0;
}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
