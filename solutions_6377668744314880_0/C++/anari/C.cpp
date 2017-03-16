#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point{
  ll x, y;
  point(){}
  point(ll x, ll y):x(x),y(y){}
  double arg() const{
    return atan2(y, x);
  }
};
ll cross(point p, point q){
  return p.x*q.y-p.y*q.x;
}
ll dot(point p, point q){
  return p.x*q.x+p.y*q.y;
}
bool operator<(const point& p, const point& q){
  return p.arg()<q.arg();
}
int n;
point p[3000];
vector<point> q;
int ans(vector<point> q){
  if (q.size()<2)
    return 0;
  vector<double> a;
  for (int i=0;i<q.size();++i){
    a.push_back(q[i].arg());
    a.push_back(q[i].arg()+2*M_PI);
  }
  sort(a.begin(), a.end());
  int n=a.size();
  int j=0;
  int ans=n;
  for (int i=0;i<n/2;++i){
    while (j<n && a[j]-a[i]<M_PI-1e-8)
      ++j;
    ans = min(ans, j-i-1);
  }
  return ans;
}
int main(){
  int tnum;cin>>tnum;
  for (int tcou=1;tcou<=tnum;++tcou){
    cin>>n;
    cout<<"Case #"<<tcou<<":"<<endl;
    for (int i=0;i<n;++i)
      cin>>p[i].x>>p[i].y;
    for (int i0=0;i0<n;++i0){
      q.clear();
      for (int i=0;i<n;++i)
        if (i!=i0){
          q.push_back(point(p[i].x-p[i0].x, p[i].y-p[i0].y));
        }
      cout<<ans(q)<<endl;
    }
  }
  return 0;
}
