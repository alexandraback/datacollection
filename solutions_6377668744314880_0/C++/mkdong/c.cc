#include <iostream>

using namespace std;

struct Point{
    long long x;
    long long y;
};

Point p[10000];

long long cross(Point x, Point y, Point k)
{
    Point a, b;
    a.x = y.x - x.x;
    a.y = y.y - x.y;
    b.x = k.x - x.x;
    b.y = k.y - x.y;
    return a.x * b.y - a.y * b.x;
}

int main()
{
    int T;
    cin >> T;
    for (int t=0; t<T; ++t) {
        int n;
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> p[i].x >> p[i].y;
        }

        cout << "Case #" << t+1 << ":" << endl;
        for (int i=0; i<n; ++i) {
            int min = n-3;
            for (int j=0; j<n; ++j) {
                if (i == j) continue;
                int on = 0;
                int less = 0;
                int more = 0;
                for (int k=0; k<n; ++k) {
                    if (i == k) continue;
                    if (j == k) continue;
                    long long r = cross(p[i], p[j], p[k]);
                    if (r == 0) on++;
                    else if (r < 0) less++;
                    else more++;
                }
                int minn = less < more ? less : more;
                if (minn < min) min = minn;
            }
            cout << min << endl;
        }
    }
    return 0;
}
