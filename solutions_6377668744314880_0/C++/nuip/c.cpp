#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<ll> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}
vector<int> convex_hull(vector<P> ps_) {
  int n = ps_.size(), k = 0;
  vector<pair<P,int>> ps(n);
  rep(i,n){
    ps[i].X=ps_[i]; ps[i].Y=i;
  }
  sort(ps.begin(), ps.end());
  vector<int> ch(2*n);
  for (int i = 0; i < n; ch[k++] = i++) // lower-hull
    while (k >= 2 && ccw(ps[ch[k-2]].X, ps[ch[k-1]].X, ps[i].X) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = i--) // upper-hull
    while (k >= t && ccw(ps[ch[k-2]].X, ps[ch[k-1]].X, ps[i].X) <= 0) --k;
  ch.resize(k-1);
  rep(i,ch.size())
    ch[i]=ps[ch[i]].Y;
  return ch;
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int i,j,k,T;
  cin>>T;
  rep(Case,T){
    int n,er,xx,yy;
    cin>>n;
    vector<P> ps(n);
    vector<int> re(n,max(0,n-3));
    rep(i,n){
      cin>>xx>>yy;
      ps[i]=P(xx,yy);
    }//cout<<ps;
    rep(i,1<<n){
      vector<P> sub;
      vector<int> inv;
      if((er=__builtin_popcount(i))<3)continue;
      er=n-er;
      rep(j,n)if(i>>j&1){
	sub.pb(ps[j]); inv.pb(j);
      }
      vector<int> con=convex_hull(sub);
      //cout<<er<<sub<<con;
      con.pb(con[0]);
      rep(k,con.size()-1){
	re[inv[con[k]]]=min(re[inv[con[k]]],er);
	rep(j,sub.size()){
	  if(ccw(sub[con[k]],sub[j],sub[con[k+1]])==-2){
	    if(inv[j]==4&&er<3,0){
	      cout<<er<<sub<<con<<inv;
	    }
	    re[inv[j]]=min(re[inv[j]],er);
	  }
	}
      }
    }
    //        rep(i,n)if(re[i]>n-3)return 1;
    cout<<"Case #"<<Case+1<<":"<<endl;
    rep(i,n)
      cout<<re[i]<<endl;
  }
  return 0;
}
