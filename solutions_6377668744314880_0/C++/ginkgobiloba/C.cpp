#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    long long x;
    long long y;
};

int onLeft(int n, int i, int j, const vector<Point>& points)
{
    int total = 0;
    for (int k = 0; k < n; ++k)
    {
        if (k != i &&k != j)
        {
            long long x1 = points[j].x - points[i].x, y1 = points[j].y - points[i].y;
            long long x2 = points[k].x - points[i].x, y2 = points[k].y - points[i].y;
            if (x1*y2 - x2*y1 > 0)
                ++total;
        }
    }
    return total;
}

void calculate(int n, const vector<Point>& points)
{
    for (int i = 0; i < n; ++i)
    {
        int minimum = n;
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                int t = onLeft(n, i, j, points);
                minimum = minimum < t ? minimum : t;
            }
        }
        cout << minimum << endl;
    }
}

int main()
{
    int cases;
    cin >> cases;
    for (int t = 1; t <= cases; ++t)
    {
        int n;
        cin >> n;
        vector<Point> points;
        points.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> points[i].x >> points[i].y;
        cout << "Case #" << t << ":" << endl;
        if (n <= 3)
        {
            for (int i = 0; i < n; ++i)
                cout << 0 << endl;
        }
        else
        {
            calculate(n, points);
        }
    }
    return 0;
}
