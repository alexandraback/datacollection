#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <deque>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mem0(ar) memset(ar, 0, sizeof(ar))
#define mem1(ar) memset(ar, -1, sizeof(ar))

struct point {
    ll x, y;
    point(ll _x, ll _y) : x(_x),y(_y){}
};

bool comparator (point a, point b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

ll turn (point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

ll turn2 (point a, point b, point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

int main()
{
    //freopen("C-large.in", "r", stdin);
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);

    int TESTS;
    cin >> TESTS;
    for (size_t test_number = 1; test_number <= TESTS; test_number++) {
        cout << "Case #" << test_number << ":" << endl;
        int N;
        cin >> N;
        vector<point> points;
        vector<point> points_copy;
        for (int i = 0; i < N; i++) {
            ll x, y;
            cin >> x >> y;
            points_copy.push_back(point(x, y));
            points.push_back(point(x, y));
        }
        vector<point> convexHull;
        if (points.size() == 1) {
            convexHull.push_back(points[0]);
        } else {
            sort (points.begin(), points.end(), &comparator);
            point p1 = points[0],  p2 = points.back();
            vector<point> up, down;
            up.push_back (p1);
            down.push_back (p1);
            for (int i = 1; i < points.size(); i++) {
                if ((i == points.size() - 1) || (turn(p1, points[i], p2) < 0)) {
                    while ((up.size() >= 2) && (turn(up[up.size()-2], up[up.size()-1], points[i]) > 0))
                        up.pop_back();
                    up.push_back (points[i]);
                }
                if ((i == points.size() - 1) || (turn(p1, points[i], p2) > 0)) {
                    while ((down.size() >= 2) && (turn(down[down.size()-2], down[down.size()-1], points[i]) < 0))
                        down.pop_back();
                    down.push_back (points[i]);
                }
            }
            for (int i = 0; i < up.size(); i++)
                convexHull.push_back(up[i]);
            for (int i = down.size() - 2; i > 0; i--)
                convexHull.push_back (down[i]);
        }
        for (int i = 0; i < N; i++) {
            bool inConvex = false;
            for (int j = 0; j < convexHull.size(); j++) {
                if ((points_copy[i].x == convexHull[j].x) && (points_copy[i].y == convexHull[j].y))
                {
                    inConvex = true;
                    break;
                }
            }

            if (inConvex)
            {
                cout << 0 << endl;
                continue;
            }
            int best_number = convexHull.size();
            for (int j = 0; j < convexHull.size(); j++) {
                int left = 0;
                int right = 0;
                for (int k = 0; k < points.size(); k++) {
                    ll turn_result = turn2(points_copy[i], convexHull[j], points_copy[k]);
                    if (turn_result < 0) left++;
                    else if (turn_result > 0) right++;
                }
                best_number = min(min(left, right), best_number);
            }
            cout << best_number << endl;
        }
    }
    return 0;
}
/*
1
9
0 0
5 0
10 0
0 5
5 5
10 5
0 10
5 10
10 10
*/
