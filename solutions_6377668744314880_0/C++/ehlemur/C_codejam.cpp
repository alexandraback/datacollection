#include <bits/stdc++.h>


const int MAX_N = 3e3 + 3;


/*long long cross ( const std::complex<long long>& a , const std::complex<long long>& b ) {
  return std::imag(std::conj(a) * b);
  }

  struct point {
  long long x, y, n;
  std::complex<long long> p;

  point ( void ) {}
  point ( int x_ , int y_ , int n_ ) : x(x_) , y(y_) , n(n_) , p(x_, y_) {}

  bool operator< ( const point& o ) const {
  return (o.x == x) ? (y < o.y) : (x < o.x);
  }
  };
 */

/*int cv_sz, m;*/
int x[MAX_N];
int y[MAX_N];
int best[MAX_N];

/*
   int convex_hull[MAX_N];

   point origin;
   point points[MAX_N];

   bool is_left ( const point& o , const point& a , const point& b ) {
   return cross(o.p - a.p, b.p - a.p) < 0;
   }
   bool by_origin ( const point& a , const point& b ) {
   if ( cross(a.p - origin.p, b.p - origin.p) == 0 ) {
   if ( std::real(a.p - origin.p) == std::real(b.p - origin.p) ) {
   return std::norm(a.p - origin.p) > std::norm(b.p - origin.p);
   }
   else {
   return std::norm(a.p - origin.p) < std::norm(b.p - origin.p);
   }
   }
   return cross(a.p - origin.p, b.p - origin.p) > 0;
   }


   void find_convex_hull ( void ) {
   int i;

   std::sort(points, points + m);
   origin = points[0];

   std::sort(points + 1, points + m, by_origin);

   cv_sz = 1;
   convex_hull[0] = 0;
   for ( i = 1 ; i < m ; ++ i ) {
   while ( cv_sz >= 2 && is_left(points[convex_hull[cv_sz-1]], points[convex_hull[cv_sz-2]], points[i]) ) {
   -- cv_sz;            
   }
   convex_hull[cv_sz ++] = i;
   }

   for ( i = 0 ; i < cv_sz ; ++ i ) {
   convex_hull[i] = points[convex_hull[i]].n;
   }
   }*/

using namespace std;

typedef long long T;
struct PT { 
    T x, y; 
    int n;
    PT() {} 
    PT(T x, T y, int n) : x(x), y(y), n(n) {}
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
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}


int main ( void ) {

    std::vector<PT> convex_hull;
    int T, N, mask_n, mask, t, n, m, i;

    std::cin >> T;

    for ( t = 1 ; t <= T ; ++ t ) {
        std::cin >> N;
        for ( n = 0 ; n < N ; ++ n ) {
            std::cin >> x[n] >> y[n];   
            best[n] = INT_MAX;
        }

        for ( mask = (1 << N) - 1 ; mask > 0 ; -- mask ) {
            convex_hull.clear();
            for ( n = m = 0 , mask_n = 1 ; n < N ; ++ n , mask_n <<= 1 ) {
                if ( mask & mask_n ) {
                    ++ m;
                    convex_hull.push_back(PT(x[n], y[n], n));
                }
            }
            ConvexHull(convex_hull);
            for ( i = 0 ; i < convex_hull.size() ; ++ i ) {
                best[convex_hull[i].n] = std::min(N - m, best[convex_hull[i].n]);
            }
        }
        std::cout << "Case #" << t << ":\n";
        for ( n = 0 ; n < N ; ++ n ) {
            std::cout << best[n] << "\n";
        }
    }

    return 0;
}
