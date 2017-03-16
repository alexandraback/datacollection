#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define NMax 15
using namespace std;
 
typedef long coord_t;         // coordinate type
typedef long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
 
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
int L[NMax][2];
int S[NMax];
int N;
vector<Point> C;
vector<Point> P;

bool contains(Point& p, vector<Point>& P)
{
  for(auto m = P.begin(); m!=P.end() ; m++)
    if( m->x == p.x && m->y == p.y)
      return true;
  for(int i=1;i<P.size();i++)
    {
      long x1 = p.x - P[i-1].x;
      long x2 = P[i].x - P[i-1].x;
      long y1 = p.y - P[i-1].y;
      long y2 = P[i].y - P[i-1].y;
      if(x1*y2 == x2*y1)
	return true;
    }
  return false;
}

void read()
{
  P.clear();
  C.clear();
  cin >> N;
  for(int i=0;i<N;i++)
    {
      cin >> L[i][0] >> L[i][1];
      Point p;
      p.x = L[i][0];
      p.y = L[i][1];
      P.push_back(p);
    }
  C = convex_hull(P);
}

int solve(int n,int indx, bool a[NMax])
{
  if(indx == N)
    {
      vector<Point> V;
      int elem =0;
      for(int i=0;i<N;i++)
	if(a[i])
	  {
	    V.push_back(P[i]);
	  }
	else
	  elem++;
      V = convex_hull(V);
      if(contains(P[n],V) && a[n])
	  return elem;
      return N;
    }
  a[indx] = true;
  int x = solve(n,indx+1,a);
  a[indx] = false;
  int y = solve(n,indx+1,a);
  if(x<y)
    return x;
  return y;
}

int solve(int n)
{
  if(contains(P[n],C))
    return 0;
  bool a[NMax];
  return solve(n,0,a);
}

void solve()
{
  for(int i=0;i<N;i++)
    S[i]=solve(i);
}

int main()
{
  int n;
  cin >> n;
  for(int t=1;t<=n;t++)
    {
      read();
      solve();
      cout << "Case #"<< t <<":\n";
      for(int i=0;i<N;i++)
	cout << S[i] << endl;
    }
  return 0;
}
