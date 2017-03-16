#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int MAX_N = 10030;

const double PI = acos(-1.0);

typedef long long ll;
//typedef pair<ll,ll> Point;

bool dEqual(ll x,ll y) { return x == y; }

struct Point {
  ll x, y;
  bool operator==(const Point &p) const { return dEqual(x, p.x) && dEqual(y, p.y); }
  bool operator<(const Point &p) const { return y < p.y || (y == p.y && x < p.x); }
};

Point operator-(Point p,Point q){ p.x -= q.x; p.y -= q.y; return p; }
Point operator+(Point p,Point q){ p.x += q.x; p.y += q.y; return p; }
Point operator*(ll r,Point p){ p.x *= r; p.y *= r; return p; }
double operator*(Point p,Point q){ return p.x*q.x + p.y*q.y; }
double len(Point p){ return sqrt(p*p); }
ll cross(Point p,Point q){ return p.x*q.y - q.x*p.y; }
Point inv(Point p){ Point q = {-p.y,p.x}; return q; }

int convex_hull(Point P[], int n, Point hull[]){
  sort(P,P+n); n = unique(P,P+n) - P;  vector<Point> L,U;
  if(n <= 2) { copy(P,P+n,hull); return n; }
  for(int i=0;i<n;i++){
    while(L.size()>1 && cross(P[i]-L.back(),L[L.size()-2]-P[i])< 0) L.pop_back();
    while(U.size()>1 && cross(P[i]-U.back(),U[U.size()-2]-P[i])> 0) U.pop_back();
    L.push_back(P[i]); U.push_back(P[i]);
  }
  copy(L.begin(),L.end(),hull); copy(U.rbegin()+1,U.rend()-1,hull+L.size());
  return L.size()+U.size()-2;
}

int ccw(const Point& a,const Point &b,const Point& c){
  ll cc = cross(b-a,c-b);
  if(cc == 0) return 0;
  if(cc > 0) return 1;
  return 2;
}

void do_case(){
  int N;
  Point A[MAX_N],BC[MAX_N];
  cin >> N;
  
  for(int i=0;i<N;i++){
    cin >> A[i].x >> A[i].y;
    BC[i] = A[i];
  }
  
  if(N <= 3){
    for(int i=0;i<N;i++)
      cout << 0 << endl;
    return;
  }
  
  Point hull[MAX_N];
  int h = convex_hull(BC,N,hull);
  
  for(int i=0;i<N;i++){
    bool on_hull = false;
    for(int j=0;j<h;j++)
      if(A[i] == hull[j])
        on_hull = true;
    if(on_hull){
      cout << 0 << endl;
      continue;
    }
    
    int best = N;
    for(int j=0;j<N;j++){
      if(i == j) continue;
      int x[3] = {0};
      for(int k=0;k<N;k++)
        if(i != k && j != k)
          x[ccw(A[j],A[i],A[k])]++;
      best = min(best,min(x[1],x[2]));
    }
    cout << best << endl;
    
  }
  
}

  int main(){
    int T,C=1;
    cin >> T;
    while(T--){
      cout << "Case #" << C++ << ":" << endl;
      do_case();
    }
    return 0;
  }
