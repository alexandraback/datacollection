#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
/* Convex Hull from CMU's former coach Richar Peng book code*/
#define sz(x) x.size()
#define foreach(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end(); ++it)
#define THETA 0.1237912487121428927431111
#define pb push_back
#define PI M_PI
const double EPS = 1e-5;
bool EQ2(double a, double b){return abs(a-b) < 1e-5;}

bool EQ(double a, double b){return abs(a-b) < EPS;}
double SQ(double d){return d*d;}
double normang(double t){ return fmod(fmod(t, 2*PI) + 2*PI, 2*PI); }//tested
double angdiff(double t1, double t2){ return normang(t1 - t2 + PI) - PI; }//tested

struct Point{
double x, y;
Point(double tx, double ty) : x(tx), y(ty) {}
Point() {}
Point add(Point p) {return Point(x+p.x, y+p.y);}
Point sub(Point p) {return Point(x-p.x, y-p.y);}
Point mult(double d) {return Point(x*d, y*d);}
double dot(Point p) {return x*p.x+ y*p.y;}
double cross(Point p) {return x*p.y - y*p.x;}
double len() {return hypot(x, y);}
Point scale(double d) {return mult(d/len());}
double dist(Point p) {return sub(p).len();}
double ang(){return atan2(y, x);}
static Point polar(double r, double theta) {
return Point(r*cos(theta), r*sin(theta));}
Point rot(double theta) {
return Point(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));
}
Point perp() {return Point(-y, x);}
bool operator==(const Point& p) {return abs(dist(p)) < EPS;}
double norm() {return dot(*this);}
string toString(){
char buf[100];
sprintf(buf, "(%f, %f)", x, y);
return buf;
}
};

double ccw(Point p1, Point p2, Point p3){ //left is 1, right is -1 
return p2.sub(p1).cross(p3.sub(p1)); 
} 



bool convexHullComp(Point a, Point b){
  return a.x < b.x;
}

vector<Point> convexHull(vector<Point> P){//attempt at minimum number of points on hull
  sort(P.begin(), P.end(), convexHullComp);
  vector<Point> ch;
  foreach(p, P) {
    if(ch.size() >= 1 && EQ(ch[sz(ch) - 1].x, p -> x)) {
      if(p -> y > ch[sz(ch) - 1].y) {
        ch.pop_back();
      } else {
        continue;
      }
    } 
    while(ch.size() >= 2 && ccw(ch[sz(ch)-2], ch[sz(ch)-1], *p) > EPS)
      ch.pop_back();
    ch.pb(*p);
  } //ch contains upper hull at this point
  vector<Point> lh;
  foreach(p, P) {
    if(lh.size() >= 1 && EQ(lh[sz(lh) - 1].x, p -> x)) {
      if(p -> y < lh[sz(lh) - 1].y) {
        lh.pop_back();
      } else {
        continue;
      }
    } 
    while(lh.size() >= 2 && ccw(lh[sz(lh)-2], lh[sz(lh)-1], *p) < -EPS)
      lh.pop_back();
    lh.pb(*p);
  }

  for(int i = lh.size() - 1; i >= 0; --i) { //concat up/low
    ch.pb(lh[i]);
  }
  return ch;
}

int main() {
  ios::sync_with_stdio(false);
  ll cases;
  cin >> cases;
  for (ll casenum = 1; casenum <= cases; casenum++) {
    ll n; cin >> n;
    Point *a = new Point[n];
    for (ll i = 0; i < n; i++) {
      cin >> a[i].x; cin >> a[i].y;
      a[i] = a[i].rot(THETA);
    }
    ll twon = 1<<n;
    ll *ans = new ll[n];
    for (ll i = 0; i < n; i++) {
      ans[i] = n;
    }
    for (ll z = 1; z < twon; z++) {
      ll pcnt = __builtin_popcountll(z);
      vector<Point> P;
      for (ll i = 0; i < n; i++) {
        if (z&(1<<i)) {
          P.pb(a[i]);
        }
      }
      vector<Point> hull = convexHull(P);
//      printf("z: %lld\n", z);
      foreach(p,hull) {
//        printf("%f, %f\n", p->x, p->y);
        for (ll i = 0; i < n; i++) {
          if (z&(1<<i)) {
            if (EQ2(p->x,a[i].x)&&EQ2(p->y,a[i].y)) {
              ans[i] = min(ans[i],n-pcnt);
            }
          }
        }
      }
    }
    cout << "Case #" << casenum << ":"<< endl;
    for (ll i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
  }
}
