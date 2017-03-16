// Round1A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "queue"
#include "vector"
#include "algorithm"
#include "string"
#include "string.h"
#include "iostream"
using namespace std;

typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
 
struct Point {
	coord_t x, y;
	int id;
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

int bitcnt(int x)
{
	int ret=0;
	while(x)
	{
		ret+=x%2;
		x/=2;
	}
	return ret;
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		vector<Point> g;
		for(int i=0;i<N;i++)
		{
			int x,y;
			cin>>x>>y;
			Point p={x,y,i};
			g.push_back(p);
		}
		vector<int> ans(N,1000);
		vector<Point> ret=convex_hull(g);
		for(int i=0;i<ret.size();i++)
		{
			ans[ret[i].id]=0;
		}
		for(int x=0;x<(1<<N);x++)
		{
			int c=0;
			vector<Point> g1;
			for(int i=0;i<N;i++)
			{
				int m=1<<i;
				if(m&x) {g1.push_back(g[i]);
				c++;
				}
			}
			if(convex_hull(g1).size()-1==c)
			{
				for(int i=0;i<N;i++)
				{
					int m=1<<i;
					if(m&x)
					{
						ans[i]=min(ans[i],N-c);
					}
				}
			}
		}
		cout<<"Case #"<<tc+1<<":"<<endl;
		for(int i=0;i<N;i++)
		{
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}