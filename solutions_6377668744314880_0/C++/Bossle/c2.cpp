//From Stanford ACM Notebook

// Compute the 2D convex hull of a set of points using the monotone chain
// algorithm.  Eliminate redundant points from the hull if REMOVE_REDUNDANT is 
// #defined.
//
// Running time: O(n log n)
//
//   INPUT:   a vector of input points, unordered.
//   OUTPUT:  a vector of points in the convex hull, counterclockwise, starting
//            with bottommost/leftmost point

#include <cstdio>
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int T;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 1; i >= 0; i--) pts.push_back(up[i]);
}

int n;
vector<PT> p;
PT s;

int main()
{
	int t;
	cin >> t;
	for(int ta=1;ta<=t;++ta)
	{
		cout << "Case #" << ta << ":\n";
		cin >> n;
		p.resize(n);
		for(int i=0;i<n;++i)
			cin >> p[i].x >> p[i].y;
		
		for(int si=0;si<n;++si)
		{
			int best=n;
			for(int i=(1<<n)-1;i>0;++i)
			{
				int cur=n;
				vector<PT> c;
				for(int bi=0;(1<<bi)<=i;bi++)
					if((1<<bi)&i)
					{
						cur--;
						c.push_back(p[bi]);
					}
				if(cur<best)
				{
					ConvexHull(c);
					for(int j=0;j<c.size();++j)
						if(c[j]==p[si])
							best=min(best,cur);
				}
			}
			cout << best << endl;
		}
	}
}
