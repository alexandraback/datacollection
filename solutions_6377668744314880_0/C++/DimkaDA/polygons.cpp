// gcj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef int coord_t;         // coordinate type
typedef int coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point {
    coord_t x, y;

    bool operator <(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }

    bool operator ==(const Point &p) const {
        return x == p.x && y == p.y;
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
    vector<Point> H(2 * n);

    // Sort points lexicographically
    sort(P.begin(), P.end());

    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
        H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
        H[k++] = P[i];
    }

    H.resize(k);
    return H;
}

int GetMinNum(vector<Point> const & trees, int ind)
{
    int res = trees.size();

    for (int i = 0; i < (1 << trees.size()); ++i)
    {
        vector<Point> newTrees;
        for (int j = 0; j < trees.size(); ++j)
        {
            int k = 1 << j;
            int m = i & (1 << j);
            if (m == 0)
                newTrees.push_back(trees[j]);
        }
        vector<Point> convex = convex_hull(newTrees);
        if (find(convex.begin(), convex.end(), trees[ind]) != convex.end())
            res = min(res, (int)trees.size() - (int)newTrees.size());
    }

    return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream ifstr("C-small-attempt0.in");
    ofstream ofstr("C-small-attempt0.out");

    int T;
    ifstr >> T;
    for (int t = 0; t < T; ++t)
    {
        int  N;
        ifstr >> N;
        vector<Point> trees(N);
        for (int i = 0; i < N; ++i)
            ifstr >> trees[i].x >> trees[i].y;

        ofstr << "Case #" << t + 1 << ":" << endl;
        for (int i = 0; i < N; ++i)
        {
            int minNum = GetMinNum(trees, i);
            ofstr << minNum << endl;
        }
    }

    return 0;
}
