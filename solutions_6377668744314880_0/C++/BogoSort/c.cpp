#include "bits/stdc++.h"
using namespace std;

class Point
{
public:
    long long x, y;
    Point() : x(0), y(0) {}
    Point(long long x, long longy) : x(x), y(y) {}
};

long long cross(Point a, Point b, Point c)
{
    return (b.x -a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void solve()
{
    int n;
    cin >> n;
    Point p[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i < n; ++i)
    {
        int mincut = n - 1;
        for (int j = 0; j < n; ++j)
        {
            if (j == i) continue;
            int cntp = 0;
            int cntn = 0;
            for (int k = 0; k < n; ++k)
            {
                if (k == i) continue;
                long long c = cross(p[i], p[j], p[k]);
                if (c < 0) ++cntn;
                if (c > 0) ++cntp;
            }
            if (cntn < mincut)
                mincut = cntn;
            if (cntp < mincut)
                mincut = cntp;
        }
        cout << mincut << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ":" << endl;
        solve();
    }
    return 0;
}
