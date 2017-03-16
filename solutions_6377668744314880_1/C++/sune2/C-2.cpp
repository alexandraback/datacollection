#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPR(i,n) for (int i=(int)(n)-1;i>=0;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
#define tpl(...) make_tuple(__VA_ARGS__)
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1);
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
typedef long long ll;
typedef pair<int,int> pii;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename Ch,typename Tr,typename C,typename=decltype(begin(C()))>basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>&os,
const C& c){os<<'[';for(auto i=begin(c);i!=end(c);++i)os<<(i==begin(c)?"":" ")<<*i;return os<<']';}
template<class S,class T>ostream&operator<<(ostream &o,const pair<S,T>&t){return o<<'('<<t.first<<','<<t.second<<')';}
template<int N,class Tp>void output(ostream&,const Tp&){}
template<int N,class Tp,class,class ...Ts>void output(ostream &o,const Tp&t){if(N)o<<',';o<<get<N>(t);output<N+1,Tp,Ts...>(o,t);}
template<class ...Ts>ostream&operator<<(ostream&o,const tuple<Ts...>&t){o<<'(';output<0,tuple<Ts...>,Ts...>(o,t);return o<<')';}
template<class T>void output(T t,char z=10){if(t<0)t=-t,putchar(45);int c[20];
int k=0;while(t)c[k++]=t%10,t/=10;for(k||(c[k++]=0);k;)putchar(c[--k]^48);putchar(z);}
template<class T>void outputs(T t){output(t);}
template<class S,class ...T>void outputs(S a,T...t){output(a,32);outputs(t...);}
template<class T>void output(T *a,int n){REP(i,n)cout<<a[i]<<(i!=n-1?',':'\n');}
template<class T>void output(T *a,int n,int m){REP(i,n)output(a[i],m);}
template<class T>bool input(T &t){int n=1,c;for(t=0;!isdigit(c=getchar())&&~c&&c-45;);
if(!~c)return 0;for(c-45&&(n=0,t=c^48);isdigit(c=getchar());)t=10*t+c-48;t=n?-t:t;return 1;}
template<class S,class ...T>bool input(S&a,T&...t){input(a);return input(t...);}
template<class T>bool inputs(T *a, int n) { REP(i,n) if(!input(a[i])) return 0; return 1;}

typedef complex<ll> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
ll cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
ll dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

// 時計回り側は含み、半時計回り側は含まない
int quadrant(const P &a) {
  ll x = real(a), y = imag(a);
  return x>0&&y>=0 ? 0 : x<=0&&y>0 ? 1 : x<0&&y<=0 ? 2 : 3;
}
// ロバストな角度比較
bool cmpAngle(const P &a, const P&b) {
  int p = quadrant(a);
  int q = quadrant(b);
  return p!=q ? p<q : cross(a,b)>0;
}

int ans[3000];

int main() {
  int T;
  cin >> T;
  REP(cs,T) {
    printf("Case #%d:\n", cs+1);
    int n;
    cin >> n;
    vector<P> v;
    REP(i,n) {
      int x,y;
      cin >> x >> y;
      v.push_back(P(x,y));
    }
    REP(cent,n) {
      vector<P> pv;
      ans[cent] = INF;
      if (n <= 2) ans[cent] = 0;
      REP(i,n) {
        if (i != cent)
          pv.push_back(v[i]-v[cent]);
      }
      sort(ALL(pv), cmpAngle);
      REP(i,n-1) pv.push_back(pv[i]);
      // cout << pv << endl;
      int idx = 0;
      REP(i,n-1) {
        chmax(idx, i+1);
        while(cross(pv[i],pv[idx]) > 0) idx++;
        // cout << i << " " << idx << endl;
        chmin(ans[cent], idx-i-1);
      }
    }
    REP(i,n) cout << ans[i] << endl;
  }

}
