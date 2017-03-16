#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>

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

int ans[20],n;
Point arr[20];

void bt(vector<Point>v,int i)
{
    if(i==n)
    {
        if(v.size()<1)
            return;
        vector<Point>v1=convex_hull(v);
        for(int f=0;f<v1.size();f++)
        {
            for(int f1=0;f1<n;f1++)
            {
                if(arr[f1].x==v1[f].x&&arr[f1].y==v1[f].y)
                    ans[f1]=min(ans[f1],n-(int)v.size());
            }
        }
        return;
    }
    v.push_back(arr[i]);
    bt(v,i+1);
    v.pop_back();
    bt(v,i+1);
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        cin>>n;
        for(int f=0;f<n;f++)
        {
            cin>>arr[f].x;
            cin>>arr[f].y;
            ans[f]=1e9;
        }
        vector<Point>v;
        bt(v,0);
        cout<<"Case #"<<tc<<":\n";
        for(int f=0;f<n;f++)
            cout<<ans[f]<<endl;
    }
}
