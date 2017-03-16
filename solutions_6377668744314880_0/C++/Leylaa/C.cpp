// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define rep(i,n) for (int i = 0; i < (n); i ++)
#define repd(i,n) for (int i = (n); i >= 0; i --)
#define PI 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef int coord_t;         // coordinate type
typedef ll coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
 
struct Point {
	coord_t x, y;
 
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return ll(A.x - O.x) * (B.y - O.y) - ll(A.y - O.y) * (B.x - O.x);
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

int main()
{
	int T;
	cin >> T;
	rep (tt, T)
	{
		int n;
		cin >> n;
		vector <Point> inp;
		rep (i, n)
		{
			Point tmp;
			cin >> tmp.x >> tmp.y;
			inp.pb (tmp);
		}
		int ans [n];
		rep (i, n)
			ans [i] = n-1;
		vector <Point> P, H;
		rep (mask, 1<<n)
		{
			rep (i, n)
				if ( mask>>i&1 )
					P.pb (inp[i]);
			H = convex_hull(P);
			P.clear();
			int m = H.size();
			rep (i, n)
				if ( mask>>i&1 && ans[i] > n-__builtin_popcount(mask) )
					rep (j, m-1)
						if ( ll(H[j].y-H[j+1].y) * (H[j].x-inp[i].x) == ll(H[j].x-H[j+1].x) * (H[j].y-inp[i].y) )
						{
							
							ans[i] = n-__builtin_popcount(mask);
							break;
						}	
		}
		
			
		printf ("Case #%d:\n", tt+1);
		rep (i, n)
			printf ("%d\n", ans[i]);
		
	}
	
	return 0;
}
