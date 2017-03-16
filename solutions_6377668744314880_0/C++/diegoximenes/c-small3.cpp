#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f

#define EPS 1e-9
const ll PI = acos(-1);


const ll eps = 1e-9;
inline int diff(ll lhs, ll rhs) 
{
	if(lhs == rhs) return 0;
	if(lhs < rhs) return -1;
	return 1;
  //if (lhs - eps < rhs && rhs < lhs + eps) return 0;
  //return (lhs < rhs) ? -1 : 1;
}
struct Point 
{
  ll x, y;
  Point() {}
  Point(ll x_, ll y_): x(x_), y(y_) {}
  bool operator==(Point o) const { return (x == o.x && y == o.y); }
};

inline int ccw(const Point& a, const Point& b, const Point& c) 
{
  return diff(a.x * b.y + b.x * c.y + c.x * a.y
  - a.y * b.x - b.y * c.x - c.y * a.x, 0);
}
inline ll dist2(const Point &a, const Point &b) 
{
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;
  return dx * dx + dy * dy;
}
struct PointSorter 
{
  Point origin;
  PointSorter(const vector<Point>& points) 
  {
    origin = points[0];
    for (int i = 1 ; i < (int)points.size() ; i++) 
    {
      int det = diff(origin.x, points[i].x);
      if (det > 0)
	origin = points[i];
      else if (det == 0 && diff(origin.y, points[i].y) > 0)
	origin = points[i];
    }
  }
  bool operator()(const Point &a, const Point &b) 
  {
    if (diff(b.x, origin.x) == 0 && diff(b.y, origin.y) == 0) return false;
    if (diff(a.x, origin.x) == 0 && diff(a.y, origin.y) == 0) return true;
    int det = ccw(origin, a, b);
    if (det == 0) return dist2(a, origin) < dist2(b, origin);
    return det < 0;
  }
};

vector<Point> convex_hull(vector<Point> points) 
{
  if (points.size() <= 3)
    return points;
  PointSorter cmp(points);
  sort(points.begin(), points.end(), cmp);
  vector<Point> ans;
  ans.push_back(points[0]);
  ans.push_back(points[1]);
  for(int i = 2 ; i < (int)points.size() ; i++) {
    while (ans.size() > 1 && ccw(ans[ans.size() - 2], ans[ans.size() - 1], points[i]) >= 0) ans.pop_back();
    ans.push_back(points[i]);
  }
  return ans;
}	

inline ll cross(Point p, Point q, Point r) { return ((r.x - q.x)*(p.y - q.y) - (r.y - q.y)*(p.x - q.x)); }
inline bool collinear(Point p, Point q, Point r) { return (cross(p, q, r) == 0); }


bool cmpMask(int mask1, int mask2) { return (__builtin_popcount(mask1) > __builtin_popcount(mask2)); }

void printMask(int mask, int n)
{
	for(int i=0; i<n; ++i)
	{
		if(mask & (1 << i)) putchar('1');
		else putchar('0');
	}
}

int main()
{
	int t, n, x, y;
	
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		
		vector<Point> v;
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf("%d %d", &x, &y);	
			v.pb(Point(x, y));
		}
		
		vector<int> vmask;
		for(int mask=0, upper=(1<<n); mask<upper; ++mask) vmask.pb(mask);
		sort(vmask.begin(), vmask.end(), cmpMask);
		
		printf("Case #%d:\n", tc);
		for(int k=0; k<n; ++k)
		{
			for(int i=0; i<(int)vmask.size(); ++i)
			{
				//printf("calculating...\n");
				//printMask(vmask[i],n); puts("");

				vector<Point> pnts;
				int mask = vmask[i];
				for(int j=0; j<n; ++j)
					if(mask & (1<<j))
						pnts.pb(v[j]);
				
				//puts("pnts=");
				//for(int j=0; j<(int)pnts.size(); ++j) printf("(%lf, %lf), ", pnts[j].x, pnts[j].y);
				//puts("");

				vector<Point> ch = convex_hull(pnts);
				//puts("oi");
				bool can = 0;
				for(int j=0; !can && j<(int)ch.size(); ++j)
					if(ch[j] == v[k])
						can = 1;
				for(int j=0; !can && j<(int)ch.size()-1; ++j)
					if(collinear(ch[j], v[k], ch[j+1]))
						can = 1;
				if(collinear(ch.back(), v[k], ch[0])) can=1;

				//printf("mask= ");
				//printMask(mask, n);
				//printf(", can= %d\n", can);
				//printf("ch=\n");
				//for(int j=0; j<(int)ch.size(); ++j) printf("(%lf, %lf), ", ch[j].x, ch[j].y);
				//puts("");

				if(can)
				{
					printf("%d\n", n - __builtin_popcount(mask));
					break;
				}
			}	
		}
	}

	return 0;
}
