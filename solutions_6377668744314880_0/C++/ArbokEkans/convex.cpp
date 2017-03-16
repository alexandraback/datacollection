/**
 * Author: Ulf Lundstrom
 * Date: 2009-04-04
 * Source: Basic algorithm knowledge
 * Description:
\\\begin{minipage}{75mm}
Rearanges the points between begin and end so that the points of the hull are in counterclockwise order between begin and the returned iterator. Points on the edge of the hull between two other points are not considered part of the hull.
\end{minipage}
\begin{minipage}{15mm}
\includegraphics[width=\textwidth]{../content/geometry/convexHull}
\end{minipage}
 * Status: tested with unitTest and Kattis problems convexhull, copsrobbers and centerofmass
 * Usage:
 * 	vector<Point<double> > p;
 * 	vector<Point<double> >
 				hull(p.begin(),convexHull(p.begin(),p.end()));
 * 	p.resize(convexHull(p.begin(),p.end())-p.begin());
 * Time: O(n)
*/
#include <algorithm>
#include <iostream>
#include "Point.h"

//using namespace std;

//change to use other types of points
typedef Point<long> ptype;
ptype refff;
bool comp(const ptype &p, const ptype &q) {
	return (p-refff).cross(q-p)>0 ||
			(p-refff).cross(q-p)==0 && (p-refff).dist2()<(q-refff).dist2();
}

template <class It>
It convexHull(It begin, It end) {
	//zero or one point always form a hull
	if (end-begin < 2) return end;
	//find a guaranteed hull point to use as origo
	refff = *min_element(begin,end);
	sort(begin, end, comp); //sort in scan order
	//place hull points first by doing a Graham scan
	It r = begin + 1;
	for (It i = begin+2; i != end; ++i) {
		while (r > begin && (*r-*(r-1)).cross(*i-*r) <= 0) --r;
		swap(*++r, *i);
	}
	if (r-begin == 1 && *begin == *r) r--;
	return ++r; //return the iterator past the last hull point
}

template <class P>
double segDist(const P& s, const P& e, const P& p) {
	if (s==e) return (p-s).dist();
	typedef typename P::coordType T;
	T d = (e-s).dist2(), t = min(d,max(T(0),(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

double EPS = 1e-10;

bool onSegment(ptype a, ptype b, ptype x) {
  return segDist(a, b, x) < EPS;
}

template <class It>
bool onBoundary(It begin, It end, ptype x) {

  It curr = begin;
  while (curr < end-1) {
    if (onSegment(*curr, *(curr+1), x)) return true;
    curr++;
  }
  if (onSegment(*begin, *(end-1), x)) return true;
  return false;
}



void solve(int t ) {
  
  int N; cin >> N;
  vector<ptype> points;
  for (int i=0; i<N; i++) {
    long x, y;
    cin >> x >> y;
    points.emplace_back(x, y);
  }

  cout << "Case #" << t << ":\n";

  for (int squirell = 0; squirell < N; squirell++) {
    ptype spoint = points[squirell];
    
    int min_to_remove = N;
    
    for (int set = 0; set < (1<<N); set++) {
      
      vector<ptype> newpoints;

      int nbits = 0;

      for (int i=0; i<N; i++) {
        if (!(set & (1<<i))) {
          newpoints.push_back(points[i]);
        }
        else nbits++;
      }
      
      if ((!(set & (1<<squirell))) && (newpoints.size() >= 3)) {
        auto it = convexHull(newpoints.begin(), newpoints.end());
        if (onBoundary(newpoints.begin(), it, spoint)) {
          min_to_remove = min(min_to_remove, nbits);
        }
      }
      
           
  
    }

    cout << min_to_remove << endl;
    
  }
  
  
  
}

int main() {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
  }
}
