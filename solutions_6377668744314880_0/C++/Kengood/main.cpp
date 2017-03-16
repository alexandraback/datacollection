#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;



const int MAX_POINT = 100; // number of points in problem, change it accordingly.
const double INF = 1000000.0; // infinity, change it accordingly.
const double PI_2 = acos (0.0); // PI / 2, i.e. 90 degree
const double PI = 2 * PI_2;

// positive epsilon, tolerance specified by problem statement
const double EPS = 1e-8; // usually use 1e-7, 1e-9, 1e-11, 1e-13, ...
const double NEPS = -EPS; // negative epsilon

/*	compare 2 double with a tolerance of EPS
	it works like strcmp () which compare 2 strings
	return:
		-1, if a is smaller than b
		0, if a is "equal" to b, accepting a tolerance of EPS
		1, if a is greater than b
*/
int dblcmp (double a, double b) {
	if (fabs (a-b) < EPS) return 0;
	return a < b ? -1 : 1;
}

typedef complex<double> Point; // or complex<int>, but not recommanded;
//	also a position-vector in maths

//	For sorting **lexicographically**
//	include this if sorting of points is needed:
namespace std {
    bool operator < (const Point& a, const Point& b) { // for sorting lexicographically
		return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
    }
}

typedef vector<Point> PointSet; // a set of points, or a polygon (in counter-clockwise order)

//	return: (signed) magnitude of "cross product" of point-vectors A and B, only a scalar
//	i.e. two times the signed area of the triangle formed by point-vectors A and B, i.e. OAB
double cross (Point a, Point b) {
	// casting can be omitted if Point is complex<double>
    return (double) real(a) * imag(b) - (double) imag(a) * real(b);
}

//	return: (signed) dot product of point-vectors A and B
double dot (Point a, Point b) {
	return real(a) * real(b) + imag(a) * imag(b);
}
int ccw (Point a, Point b, Point c) { // short version
	return dblcmp (cross (b-a, c-a), 0);
}



Point _pivot; // global variable
bool angularCompare (Point pa, Point pb) {
	switch (ccw (_pivot, pa, pb)) {
	case 1: // area > 0 => p0 -> pa -> pb => place pa first (and ignore pa in Graham Scan)
		return true;

	case -1: // area < 0 => p0 -> pb -> pa => place ba first (and ignore pb in Graham Scan)
		return false;

	default: // (area == 0) => (p0, pa, pb are collinear)
		return abs (pa - _pivot) < abs (pb - _pivot);
	}
}

int findPivot (const PointSet& pool) {
	int n = pool.size(), pv = 0; // index of pivot in the pool
	Point pivot = pool[0];
	for (int i=1; i < n; ++i)
		if (imag(pool[i]) < imag(pivot) || // the lowest
			(imag(pool[i]) == imag(pivot) && real(pool[i]) < real(pivot))) { // leftmost
				pv = i; pivot = pool[i];
		}
	return pv;
}
void GrahamScan (PointSet &pool, PointSet &hull)
{
	// Step 1: Find the pivot, and make pool[0] the pivot by swapping
	int pv = findPivot (pool); // index of pivot in the pool
	swap (pool [0], pool [pv]);
	_pivot = pool[0];

	// Step 2: Sort the points angularly about the pivot
	sort (pool.begin() + 1, pool.end(), angularCompare); // need to include <algorithm>

	// Step 3: Push p0 and p1
	hull.clear();
	hull.push_back (pool [0]); hull.push_back (pool [1]);

	// Step 4: Find the vertices of the hull (the "hull" behaves like a stack)
	for (int i=2, n=pool.size(), top=1; i < n; ++i) {
		// while Pi is loosely right of S(t-1) St
		while (top > 0 && ccw (hull [top-1], hull [top], pool [i]) <= 0) {
			hull.pop_back(); --top; // pop
		}
		hull.push_back (pool [i]); ++top; // push Pi
	}
}


/*	Determine if a point is inside a polygon - The "Point in polygon" problem
	pre:
		provide a global variable: PointSet trans
		the para poly had better arrange in counter-clockwise order
	return:
		'v': p is a vertex of the polygon, otherwise
		'e': p is on an edge of th polygon, otherwise
		'i': p is strictly inside the polygon
		'o': p is strictly outside the polygon
	Optional: change EPS and NEPS to 0 for Point as complex<int>
*/
PointSet trans; // global variable: a translation of poly
char pointInPolygon (const PointSet& poly, const Point &p)
{
    int n = poly.size(), 
        i, k, // i, k are two consecutive vertices
        left_cross = 0, // left crossing counter
        right_cross = 0; // right crossing counter
    bool isVertex = false, 
        left_int, right_int; // left_intersect and right_intersect
    double x;

    // Translate the polygon:
    trans.clear(); // important
    for (i=0; i<n; ++i) trans.push_back (poly[i] - p);
    trans.push_back (trans[0]); // to ease wrap around

    for (i=n-1, k=0; k < n; i = k++) { // for each edge of the translation
        if (fabs (real(trans[i])) < EPS && fabs (imag(trans[i])) < EPS) {
            isVertex = true; // p is a vertex of the polygon
            break;
        }

        left_int = (imag(trans[i]) < NEPS != imag(trans[k]) < NEPS); 
        right_int = (imag(trans[i]) > EPS != imag(trans[k]) > EPS);
        if (left_int || right_int) {
            x = (real(trans[i]) * imag(trans[k]) - real(trans[k]) * imag(trans[i]))
                / (double) (imag(trans[k]) - imag(trans[i]));
            if (left_int && (x < NEPS)) ++left_cross;
            if (right_int && (x > EPS)) ++right_cross;
        }
    }

    if (isVertex) return 'v';                                // p is a vertex of the polygon
    if ( (left_cross & 1) != (right_cross & 1) ) return 'e'; // p is on edge of the polygon
    if (right_cross & 1) return 'i';                         // p is strictly inside
    return 'o';                                              // p is strictly outside
}


int brute(PointSet input , int tar)
{
	int n = input.size();
	int ans = n-2;
	for (int mask = 0 ; mask < (1<<n)-1; ++mask)
	{
		//if ( (mask& (1<<tar)) == 0 )
		//	continue;
		PointSet tryIt;
		int t = 0;
		for (int i = 0 ; i < n; ++i)
		{
			if ( (mask& (1<<i)))
			{
				tryIt.push_back( input[i]);
			}
			else 
			{
				if (i!=tar)
				++t;
			}
		}

		if ( (mask& (1<<tar)) == 0 && (mask|(1<<tar)) != (1<<n)-1)
			tryIt.push_back( input[tar]);

		char ok = 0;
		if ( n-t > 2)
		{
			PointSet hull;
			GrahamScan(tryIt,hull);
			
			for (int i = 0 ; i < hull.size(); ++i)
			if ( hull[i] == input[tar])
			{
				ok = 1; break;
			}
			if (!ok)
			{
				char r = pointInPolygon(hull, input[tar]);
				if (r == 'v' || r == 'e')
					ok = 1;
			}
		}
		else
		{
			ok = 1;
		}
		if (ok)
			ans = min(ans , t);
	}

	return ans;
}


int main(int a, char **ag)
{	
	int Case, cases = 0;
	scanf("%d" , &Case);
	int SKIP = -1, START = -1;
	if (a > 1 )
	{
		SKIP = atoi(ag[2]);
		START = atoi(ag[1]);
	}

	while (Case--)	
	{

		int n;
		cin >> n;
		PointSet input(n) , hull, temp;
		for (int i = 0 ; i < n; ++i)
		{
			double x , y;
			cin >> x >> y;
			input[i] = Point(x,y);
		}


		//if (START!=-1)
		//{
		//	if (++cases < START)
		//		continue;
		//	--cases;
		//}

		//if (SKIP!=-1)
		//{
		//	if (++cases > SKIP)
		//		return 0;
		//	--cases;
		//}

		printf("Case #%d:\n" , ++cases);
		temp = input;
		if (n > 2)
			GrahamScan(temp,hull);

		for (int i = 0 ; i < n; ++i)
		{
			int ans = 0;
			if (n > 2 && hull.size() > 2)
			{
				char r = pointInPolygon(hull, input[i]);
				if (r == 'o' )
				{
					cerr << ("wtf?");
					cerr << hull.size() ;
				}

				if (r == 'i')
				{
					//dont know geometryyyyyyy
					ans =	brute(temp, i);			
				}
			}
			cout << ans << endl;
		}
		
	}

	return 0;
}

