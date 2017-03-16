// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <algorithm>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
 
typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
 
struct Point {
    coord_t x, y;
 
    bool operator <(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};
 
// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
    int n = P.size(), k = 0;
    vector<Point> H(2*n);
 
    // Sort points lexicographically
    sort(P.begin(), P.end());
 
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
        H[k++] = P[i];
    }
 
    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
        H[k++] = P[i];
    }
 
    H.resize(k);
    return H;
}

Point points[3005];
vector<Point> curTrees;
bool works(int wantToBorder) {
    vector<Point> newTrees = curTrees;
    vector<Point> p = convex_hull(newTrees);
    bool result = false;
    for (int i = 0; i < p.size(); i++) {
        if (points[wantToBorder].x == p[i].x && points[wantToBorder].y == p[i].y) {
            result = true;
        }
    }
    // for (int i = 0; i < curTrees.size(); i++) {
    //     cout << X(curTrees[i]) << " " << Y(curTrees[i]) << endl;
    // }
    // cout << "FIRST " << X(points[wantToBorder] ) << " " << Y(points[wantToBorder]) << endl;
    // for (int i = 0; i < p.size(); i++) {
    //     cout << X(p[i]) << " " << Y(p[i]) << endl;
    // }
    // cout << result << endl << endl;
    return result;
}

int t, treeCount;
int minWork(int curIndex, int numChanged, int wantToBorder) {
    if (curIndex == treeCount) {
        if (works(wantToBorder))  {
            return numChanged;
        }
        return 9999999;
    }
    int min1 = minWork(curIndex + 1, numChanged + 1, wantToBorder);
    curTrees.push_back(points[curIndex]);
    int min2 = minWork(curIndex + 1, numChanged, wantToBorder);
    curTrees.pop_back();
    return min(min1, min2);
}

int main() {
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cin >> treeCount;
        for (int i = 0; i < treeCount; i++) {
            double p1, p2;
            cin >> p1 >> p2;
            Point p;
            p.x = p1; p.y = p2;
            points[i] = p;
        }
        cout << "Case #" << test << ":" << endl;
        for (int i = 0; i < treeCount; i++) {
            int min = minWork(0, 0, i);
            cout << min << endl;
        }
    }
}