#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define pb(a) push_back(a)
#define pr(a) cout<<(a)<<endl
#define PR(a,b) cout<<(a)<<" "<<(b)<<endl
#define R cin>>
#define F first
#define S second
#define ll long long
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
const double EPS = 1e-10;
const double INF = 1e12;
typedef complex<double> P; //Point
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {//外積
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {//内積
  return real(conj(a)*b);
}

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > EPS)   return +1;       // counter clockwise
  if (cross(b, c) < -EPS)   return -1;       // clockwise
  if (dot(b, c) < -EPS)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;                               // a--c--b on line
}

int main() {
  int T;
  R T;
  REP(t,1,T+1) {
    int n;
    R n;
    P a[n];
    rep(i,n) {
      int x,y;
      cin >> x >> y;
      a[i]=P(x,y);
    }
    cout << "Case #" << t << ":" << endl;
    rep(i,n) {
      int ans=MAX;
      rep(j,n) {
	if(i==j) continue;
	int cnt=0,c=0;
	rep(k,n) {
	  if(i==k || j==k) continue;
	  int cc=ccw(a[i],a[j],a[k]);
	  if(cc==1) cnt++;
	  else if(cc!=-1) c++;
	}
	//cout << i << " " << j << " " << cnt << " " << n-cnt-c-2 << endl;
	ans=min(ans,min(cnt,n-cnt-c-2));
      }
      if(ans==MAX) ans=0;
      pr(ans);
    }
  }
  return 0;
}
