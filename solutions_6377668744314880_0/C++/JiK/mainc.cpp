/* My Template for the Google Code Jam.
 *
 * Compile: g++ -std=c++11 -lgmp -lgmpxx
 *  - I'm probably using some C++11 features.
 *  - I might use GMP (GNU Multiple Precision Arighmetic Library) so
 *    I'm including the library in the template even if they
 *    won't be used.
 *
 * This code is ugly but it works - otherwise you wouldn't be reading
 * it, right?
 */

#include <cassert>
//#define NDEBUG

#include <cstdlib>
#include <cstdint>
#include <cmath>

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#include <gmpxx.h>

using namespace std;
typedef size_t szt;

typedef long long ll;
typedef unsigned long long ull;

typedef mpz_class mpz;

template<typename T>
void read_to_vector(size_t N, std::vector<T> &v) {
  for(size_t i=0; i<N; i++) {
    T tmp;
    std::cin >> tmp;
    v.push_back(tmp);
  }
}
template<typename T>
void print_vector(const std::vector<T> &v) {
  for(auto it = v.begin(); it<v.end(); it++) {
    if(it==v.begin())
      std::cout << " ";
    std::cout << (*it);
  }
}

//Copy functions from TCR here.



template<typename T> T dotProduct(T x0, T y0, T z0,
				  T x1, T y1, T z1) {
  return x0*x1+y0*y1+z0*z1;
}
template<typename T> T distSquared(T x0, T y0, T z0,
				  T x1, T y1, T z1) {
  return (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1) + (z0-z1)*(z0-z1);
}

//Distance of point (x,y,z) from a line (x0,y0,z0)..(x1,y1,z1)
template<typename T> double distPointLine(T x, T y, T z,
					  T x0, T y0, T z0,
					  T x1, T y1, T z1) {
  
  //square of length of p1-p0
  T lensq = distSquared(x0,y0,z0,x1,y1,z1);

  //component p-p0 in direction of p1-p0
  T dp = dotProduct(x-x0,y-y0,z-z0,x1-x0,y1-y0,z1-z0);
  double com = ((double)dp) / sqrt((double)lensq);
  
  //Pythagoras
  return sqrt(std::max((T)0,distSquared(x0,y0,z0,x,y,z)-com*com));
}


//Distance of point (x,y,z) from a ray (x0,y0,z0)..(x1,y1,z1)
template<typename T> double distPointRay(T x, T y, T z,
					 T x0, T y0, T z0,
					 T x1, T y1, T z1) {

  if(dotProduct(x1-x0,y1-y0,z1-z0,x-x0,y-y0,z-z0)<=0)
    return sqrt((double)distSquared(x,y,z,x0,y0,z0));

  return distPointLine(x,y,z, x0,y0,z0, x1,y1,z1);
}


//Geometry
template<typename T, size_t N>
struct Point {
  std::array<T,N> vals;
  
  Point<T,N> () {}
  Point<T,N> (T x, T y) {
    vals[0] = x;
    vals[1] = y;
    if(N==3) vals[2] = 0;
  }
  Point<T,N> (T x, T y, T z) {
    vals[0] = x;
    vals[1] = y;
    vals[2] = z;
  }

  friend Point<T,N> operator+ (const Point<T,N> &p1, const Point<T,N> &p2) {
    Point<T,N> res;
    for(int i=0; i<N; i++)
      res.vals[i] = p1.vals[i]+p2.vals[i];
    return res;
  }
  friend Point<T,N> operator- (const Point<T,N> &p1, const Point<T,N> &p2) {
    Point<T,N> res;
    for(int i=0; i<N; i++)
      res.vals[i] = p1.vals[i]-p2.vals[i];
    return res;
  }
  friend Point<T,N> operator* (const T &c, const Point<T,N> &p) {
    Point<T,N> res;
    for(int i=0; i<N; i++)
      res.vals[i] *= c;
    return res;
  }
  bool operator<(const Point<T,N> &p) const { // Only 2D sorting!
    assert(N==2);
    if(p.vals[0]==0 && p.vals[1]==0) return false;
    bool pa = (  vals[1]>0 ||   vals[1]==0 &&   vals[0]>=0);
    bool pv = (p.vals[1]>0 || p.vals[1]==0 && p.vals[0]>=0);
    if(pa==pv)
      return (this->cross2d(p)>0) ? true : false;
    else
      return pa;
  }

  T cross2d (const Point<T,N> &p) const {
    assert(N==2);
    return p.vals[1]*vals[0]-p.vals[0]*vals[1];
  }
  T dot( const Point<T,N> &p2) const {
    T sum=0;
    for (int i=0; i<N; i++)
      sum += vals[i]*p2.vals[i];
    return sum;
  }
  double lensq() const{
    return this->dot(*this);
  }
  double len() const{
    return std::sqrt(this->lensq());
  }
  Point<T,N> getNormalize() const { //Returns 0 vector if this is a 0 vector.
    if(this->lensq() == 0) return *this;
    return (*this) /(this->len());
  }
};

template<typename T> using Point2 = Point<T,2>;



//Solution:

ll countorigin(int N, vector<Point2<ll>> trees) {
  if(N <= 2) {
    return 0;
  }

  sort(trees.begin(), trees.end());
 
  //  trees.erase(trees.begin());
  //  N--;
  //  cerr << trees[0].vals[0] << " " << trees[0].vals[1] << "\n";

  int minres = N;
  int lasti = 0;
  for(int firsti = 0; firsti < N; firsti++) {
    if(lasti == firsti) {
      lasti = (lasti+1)%N;
    }
    cerr << "Firsti: " << firsti << "-(" << trees[firsti].vals[0] <<"," 
	 << trees[firsti].vals[1] << ")" << "\n";
    if(trees[firsti].cross2d(trees[(firsti+1)%N]) == 0 &&
       trees[firsti].dot(trees[(firsti+1)%N]) > 0
       ) {
      //      continue; // can't be firsti.
    }
    while((trees[firsti].cross2d(trees[lasti]) > 0) //||
	   //(trees[firsti].cross2d(trees[(lasti)%N]) == 0 &&
	   //	    trees[firsti].dot(trees[(lasti)%N]) > 0) ) &&
	   //	  lasti != firsti
	  ) {
      lasti ++;
      lasti %= N;
    }
    cerr << "Lasti: " << lasti << "-(" << trees[lasti].vals[0] <<"," 
	 << trees[lasti].vals[1] << ")" << "\n";
    minres = min(minres, (lasti - firsti - 1 + N) % N);
  }

  return minres;
}


void solve() {
  int N;
  cin >> N;
  vector<Point2<ll>> trees;
  for(int i=0; i<N; i++) {
    ll x, y;
    cin >> x;
    cin >> y;
    trees.push_back(Point2<ll>(x, y));
  }

  for(int i=0; i<N; i++) {
    vector<Point2<ll>> trees2;
    for(int j=0; j<N; j++) {
      if(i!=j) {
	trees2.push_back(trees[j] - trees[i]);
	cerr << "New tree:" << trees2.back().vals[0] << " " << trees2.back().vals[1] << "\n";
      }
    }
    cout << countorigin(N-1, trees2) << "\n";
  }
}

//This is executed before any input is read.
void pre_compute() {
  
}

int main() {
  std::cout << std::setprecision(15);
  pre_compute();
  size_t T;
  std::cin >> T;
  for(size_t i=1; i<=T; i++) {
    //CHOICE B
    std::cout << "Case #" << i << ":";
    std::cout << "\n"; //Either of these should be removed.
    solve();
  }

  return 0;
}
