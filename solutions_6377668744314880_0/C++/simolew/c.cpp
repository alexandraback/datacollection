#include <iostream>
#include<algorithm>
#include <stack>
#include <stdlib.h>
#include<vector>
#include<set>
typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
using namespace std;

struct point {
    coord_t x, y;
    int i;
    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};
double epsilon = 1e-10;
double abs(double a) {
    return a > 0 ? a : -a;
}
bool isBetween(point a, point b, point c) {
    double cr = (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y);
    if(abs(cr) > epsilon) return false;
    int dot = (c.x - a.x) * (b.x - a.x) + (c.y - a.y)*(b.y - a.y);
    if(dot < 0) return false;
    int sq = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
    if(dot > sq) return false;
    return true;
}
 
 
 
// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const point &O, const point &A, const point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<point> convex_hull(vector<point> P)
{
    int n = P.size(), k = 0;
    vector<point> H(2*n);
 
    // Sort points lexicographically
    sort(P.begin(), P.end());
 
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
 
    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
 
    H.resize(k);
    return H;
}


void f() {
    int n;
    cin>>n;
    vector<point> points;
    for(int i=0;i<n;i++) {
        point a;
        cin>>a.x>>a.y;
        a.i=i;
        points.push_back(a);
    }


    vector<int> best (n, n-1);
    for(int mask = 0; mask < (1<<n); mask++)  {
        vector<point> npoints;
        int removed=0;
        for(int i=0;i<n;i++) {
            bool inc = (1<<i) & mask;
            if(inc) npoints.push_back(points[i]);
            else removed++;
        }

        if(removed == n) continue;
                
        vector<point> poly = convex_hull(npoints);
        for(int t=0;t<n;t++) {
            point c = points[t];
            bool l = false;
            for(int i=0;i<poly.size()-1;i++) {
            
                point a = poly[i];
                point b = poly[(i+1)%poly.size()];
                if(a.i==c.i ||b.i==c.i) l=true;
                if(isBetween(a,b,c)) {

                    l=true;
                }
            }


                
            if(l) {
                best[t] = min(removed,best[t]);
            }

        }
    }
    for(int i=0;i<n;i++) cout<<best[i]<<endl;
}

int main()
{
    int T=0;
    cin>>T;
    for(int i=1;i<=T;i++) { cout<<"Case #"<<i<<":\n"; f();}
}
