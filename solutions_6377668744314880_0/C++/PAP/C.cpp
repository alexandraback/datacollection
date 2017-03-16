#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point {
	coord_t x, y;

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; ++i)
	{
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) 
			k--;
		H[k++] = P[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--)
	{
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) 
			k--;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}

int x[100], y[100], ans[100];
int n;

bool check(int X, int k)
{
	vector<Point> v;
	if(((X >> k) & 1) == 1)
		return false;
	for(int i = 0; i < n; i++)
		if(((X >> i) & 1) == 0)
		{
			Point t;
			t.x = x[i], t.y = y[i];
			v.push_back(t);
		}
	if(v.size() == 1)
		return 1;
	vector<Point> o = convex_hull(v);
	Point p;p.x = x[k], p.y = y[k];			
	for(int j = 0; j < o.size() - 1; j++)
		if(cross(p, o[j], o[j + 1]) == 0)
			return 1;
	return 0;
}

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		for(int i = 0; i < n; i++)
		{
			ans[i] = 1e9;
			for(int j = 0; j < (1 << (n + 1)); j++)
				if(check(j, i))
					ans[i] = min(ans[i], __builtin_popcount(j));
		}
		cout << "Case #" << tt << ":\n";
		for(int i = 0; i < n; i++)
			cout << ans[i] << endl;
		cerr << tt << endl;
	}
	return 0;
}

