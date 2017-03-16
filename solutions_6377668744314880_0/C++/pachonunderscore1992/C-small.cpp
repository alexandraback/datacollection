#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 16;
const double EPS = 1e-6;

#define Vector Point

struct Point{
   double x, y;
   Point(){}
   Point(double a, double b) { x = a; y = b; }
   double mod2() { return x*x + y*y; }
   double mod()  { return sqrt(x*x + y*y); }
   double arg()  { return atan2(y, x); }
   Point ort()   { return Point(-y, x); }
   Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }
bool operator ==(const Point &a, const Point &b){
   return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b){
   return !(a==b);
}
bool operator <(const Point &a, const Point &b){
   if(abs(a.x - b.x) > EPS) return a.x < b.x;
   return a.y + EPS < b.y;
}

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

vector<Point> ConvexHull(vector <Point> P){
   sort(P.begin(),P.end());
   int n = P.size(),k = 0;
   Point H[2*n];
   for(int i=0;i<n;++i){
      while(k>=2 && area(H[k-2],H[k-1],P[i]) < 0) --k;
      H[k++] = P[i];
   }
   for(int i=n-2,t=k;i>=0;--i){
      while(k>t && area(H[k-2],H[k-1],P[i]) < 0) --k;
      H[k++] = P[i];
   }
   return vector <Point> (H,H+k-1);
}

int n, m;
vector<Point> v;
vector<Point> hull;

int bitcount(int mask) {
   return __builtin_popcount(mask);
}

int solve(int p) {
   if(n <= 3){
      return 0;
   }
   int mini = -1;
   for(int mask = 0 ; mask < (1 << n) ; mask++){
      vector<Point> nhull, nv;
      mask |= (1 << p);
      for(int i = 0 ; i < n ; i++) {
         if(mask&(1 << i)){
            nv.push_back(v[i]);
         }
      }
      nhull = ConvexHull(nv);
      int M = nhull.size();
      bool sw = 0;
      for(int i = 0 ; i < M ; i++) {
         if(v[p] == nhull[i]){
            sw = true;
         }
      }
      if(sw) {
         int r = n - bitcount(mask);
         if(mini == -1 || r < mini) {
            mini = r;
         }
      }
   }
   return mini;
}

int main(){
#ifndef ONLINE_JUDGE
   // freopen("in","r",stdin);
   freopen("C-small-attempt1.in","r",stdin);
   freopen("C-small-attempt1.out","w",stdout);
#endif
   int casos;
   cin >> casos;
   for(int caso = 1 ; caso <= casos ; caso++){
      cin >> n;
      int x, y;
      v = vector<Point>(n);
      for(int i = 0 ; i < n ; i++){
         cin >> x >> y;
         v[i] = (Point(x,y));
      }
      cout << "Case #" << caso << ":" << endl;
      for(int i = 0 ; i < n ; i++){
         cout << solve(i) << endl;
      }
   }
   return 0;
}