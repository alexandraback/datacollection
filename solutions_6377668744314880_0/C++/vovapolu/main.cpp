#include <iostream>
#include "../../gcjoutput.h"
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
	long long x, y;
	int id;
};

bool cmp(const Point &a, const Point &b) {
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

bool cw(Point a, Point b, Point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(Point a, Point b, Point c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void convex_hull(vector<Point> &points) {
	if (points.size() <= 1)
        return;
	sort (points.begin(), points.end(), cmp);
	Point p1 = points[0],  p2 = points.back();
	vector<Point> up, down;
	up.push_back(p1);
	down.push_back(p1);
	for (int i = 1; i < points.size(); i++) {
		if (i == points.size() - 1 || cw(p1, points[i], p2)) {
			while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], points[i]))
				up.pop_back();
			up.push_back(points[i]);
		}
		if (i == points.size() - 1 || ccw(p1, points[i], p2)) {
			while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], points[i]))
				down.pop_back();
			down.push_back(points[i]);
		}
	}
	points.clear();
	for (int i = 0; i < up.size(); i++)
		points.push_back(up[i]);
	for (int i = down.size() - 2; i > 0; i--)
		points.push_back(down[i]);
}

vector <Point> now;
int minval;

void checkPoint(int id, const vector<Point> &ps, int num) {
    if (num >= ps.size()) {
        if (ps.size() - now.size() >= minval)
            return;
        vector <Point> vec = now;
        convex_hull(vec);
        for (int i = 0; i < vec.size(); i++) {
            int j = (i + 1) % vec.size();
            if (!cw(vec[i], vec[j], ps[id]) && !cw(vec[j], vec[i], ps[id])) {
                minval = ps.size() - now.size();
                /*if (minval == 0) {
                    cout << vec[i].x << ' ' << vec[i].y << ' '
                    << vec[j].x << ' ' << vec[j].y << ' '
                    << ps[id].x << ' ' << ps[id].y << endl;
                }*/
                return;
            }
        }
    } else {
        checkPoint(id, ps, num + 1);
        now.push_back(ps[num]);
        checkPoint(id, ps, num + 1);
        now.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector <Point> ps(n);
        for (int i = 0; i < n; i++) {
            cin >> ps[i].x >> ps[i].y;
            ps[i].id = i;
        }

        output << nextCase << '\n';

        for (int j = 0; j < n; j++) {
            minval = numeric_limits<int>::max();
            now.clear();
            checkPoint(j, ps, 0);
            output << minval;
            if (j != n - 1)
                output << '\n';
        }
    }
    return 0;
}
