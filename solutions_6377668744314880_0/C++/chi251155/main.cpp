#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

typedef int coord_t;         // coordinate type
typedef int coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

typedef pair<int, int> Point;
 
bool comb(Point &x, Point &y) { return x.first < y.first || (x.first == y.first && x.second < y.second); }

bool same(Point &x, Point &y) { return x.first == y.first && x.second == y.second; };

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
    return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}
 
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> &P)
{
    int n = P.size(), k = 0;
    vector<Point> H(2*n);
 
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        //while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
 
    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        //while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
 
    H.resize(k);
    return H;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        vector<Point> ps;
        ps.reserve(N);
        for(int i = 0; i < N; ++i)
        {
            int x, y;
            cin >> x >> y;
            Point p = make_pair(x, y);
            ps.push_back(p);
        }
        // Sort points lexicographically
        sort(ps.begin(), ps.end(), comb);
        
        vector<Point> rps(ps);
        map<Point, int> pointToLayerMap;
        int layer = 0;
        while(rps.size() > 1)
        {
            const vector<Point> h = convex_hull(rps);
            for(auto it = h.begin(); it != h.end() - 1; ++it)
            {
                Point p = *it;
                pointToLayerMap[p] = layer;
                auto it2 = find_first_of(rps.begin(), rps.end(), it, it + 1);
                if(it2 != rps.end()) rps.erase(it2);
            }
            ++layer;
        }
        pointToLayerMap[rps[0]] = layer;
        cout << "Case #" << t << ":" << endl;
        for(auto it = ps.begin(); it != ps.end(); ++it)
        {
            cout << pointToLayerMap[*it] << endl;
        }
    }
    return 0;
}
