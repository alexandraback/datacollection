#include <iostream>
#include <stack>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
 
struct Point
{
    long long x;
    long long y;
};
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    long long val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
int n;
Point pts[3000];

int calc(struct Point & p, struct Point & q)
{
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        int val = orientation(q, p, pts[i]);
        if (val == 0 || val == 1)
            ++cnt1;
        if (val == 0 || val == 2)
            ++cnt2;
    }
//    cout << cnt1 << " " << cnt2 << endl;
    return n - max(cnt1, cnt2);
}

int cutTree(struct Point & p)
{
    if (n < 3)
        return 0;
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (pts[i].x != p.x || pts[i].y != p.y) {
            ans = min(ans, calc(p, pts[i]));
        }
    }
    return ans;
}


void work(ifstream & fin, int caseno)
{
    fin >> n;
    for (int i = 0; i < n; ++i)
        fin >> pts[i].x >> pts[i].y;
    
    cout << "Case #" << caseno << ":" << endl;
    for (int i = 0; i < n; ++i)
        cout << cutTree(pts[i]) << endl;
}

int main()
{
    ifstream fin;
    fin.open("input");

    int c;
    fin >> c;
    for (int i = 0; i < c; ++i)
    {
        work(fin, i + 1);
    }

    fin.close();
}
