#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

#define foreach(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) { };
    ll len() const { return x * x + y * y; }
};

Point operator - (const Point& l, const Point& r)
{
    return Point(l.x - r.x, l.y - r.y);
}

Point operator + (const Point& l, const Point& r)
{
    return Point(l.x + r.x, l.y + r.y);
}

ll operator *(const Point& l, const Point& r)
{
    return (ll)l.x * r.y - (ll)l.y * r.x;
}

bool operator < (const Point& l, const Point& r)
{
    return l.len() < r.len();
}

bool inside(const Point& a, const Point& b, const Point& c, const Point& x)
{
    ll s1 = abs((x - a) * (x - b));
    ll s2 = abs((x - b) * (x - c));
    ll s3 = abs((x - a) * (x - c));
    if (!s1 || !s2 || !s3)
        return false;
    ll s = abs((a - b) * (c - b));
    return s1 + s2 + s3 == s;
}

bool oneline(const Point& a, const Point& b, const Point& c)
{
    if ((b-a) * (c-a))
        return false;
    return b - a < c - a;
}

bool is_good(const vector<Point> pts, int p, int mask)
{
    int left_v = 1000000000;
    int left = -1;
    for (int i = 0; i < pts.size(); i++)
        if (mask & (1 << i))
            if (pts[i].x < left_v || pts[i].x == left_v && pts[i].y < pts[left].y) {
                left_v = pts[i].x;
                left = i;
            }

    if (pts[p].x == left_v)
        return true;

    for (int j = 0; j < pts.size(); j++)
        if ((mask & (1 << j)) && j != left && j != p)
            if (oneline(pts[left], pts[p], pts[j])) {
                bool found[2] = { false, false };
                for (int k = 0; k < pts.size(); k++)
                    if ((mask & (1 << k))) {
                        ll mul = (pts[k] - pts[left]) * (pts[p] - pts[left]);
                        if (mul < 0)
                            found[0] = true;
                        else if (mul > 0)
                            found[1] = true;
                    }
                return ! (found[0] && found[1]);
            }

    for (int j = 0; j < pts.size(); j++)
        if ((mask & (1 << j)) && j != left && j != p)
            for (int k = j + 1; k < pts.size(); k++)
                if ((mask & (1 << k)) && k != left && k != p)
                    if (inside(pts[left], pts[j], pts[k], pts[p]))
                        return false;

    return true; 
}

int main(int argc, const char* argv[])
{
    int T;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Point> pts(N);
        for (int i = 0; i < N; i++)
            cin >> pts[i].x >> pts[i].y;
        cout << "Case #" << t << ":" << endl;
        for (int i = 0; i < N; i++) {
            int mxc = min(3, N);
            for (int mask = 0; mask < (1 << N); mask++) {
                int txc = __builtin_popcount(mask);
                if (txc <= mxc)
                    continue;
                if (!(mask & (1 << i)))
                    continue;
                if (is_good(pts, i, mask))
                    mxc = txc;
            }
            cout << N - mxc << endl;
        }
    }
    return 0;
}
