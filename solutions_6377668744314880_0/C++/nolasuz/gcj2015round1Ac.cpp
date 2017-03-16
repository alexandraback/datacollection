#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}


#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
// #define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define eps 1e-8
static const int INF=1<<24;
typedef complex<double> P;
namespace std {
  bool operator <(const P &a, const P &b) {
    if(a.real() != b.real()) return a.real() < b.real();
    return a.imag() < b.imag();
  }
}
 
double dot(P a, P b) {
  return a.real()*b.real() + a.imag()*b.imag();
}
 
double cross(P a, P b) {
  return a.real()*b.imag() - a.imag()*b.real();
}
 
int ccw(P p, P a, P b) {
  a -= p;
  b -= p;
  if(cross(a,b) > eps) return 1;
  if(cross(a,b) < -eps) return -1;
  if(dot(a,b) < -eps) return 2;
  if(norm(b)-norm(a) > eps) return -2;
  return 0;
}
vector<P> convex_hull(vector<P> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2*n);
  for(int i = 0; i < n; ch[k++] = ps[i++])
    while(k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0&&ccw(ch[k-2], ch[k-1], ps[i]) !=-2) --k;
  for(int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--])
    while(k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0&&ccw(ch[k-2], ch[k-1], ps[i]) !=-2) --k;
  ch.resize(k-1);
  return ch;
}
void mainmain(){
	int T;
	cin>>T;
	rep(o,T){
		cout<<"Case #"<<o+1<<": "<<endl;
		int n;
		cin>>n;
		vector<P> v(n);
		rep(i,n){
			double a,b;
			cin>>a>>b;
			v[i]=P(a,b);
		}
		vector<P> g=convex_hull(v);
		set<P> se;
		rep(i,g.size()){
			se.insert(g[i]);
		}
		rep(i,n){
			if(se.find(v[i])!=se.end()){
				cout<<0<<endl;
				continue;
			}
			if(n<=3){
				cout<<0<<endl;
				continue;
			}
			int ans=n-3;
			rep(j,1<<n){
				// cout<<"j "<<j<<endl;
				if((j&(1<<i))==0){
					// puts("hoge");
					continue;
				}
				vector<P> tmp;
				rep(k,n){
					if(j&1<<k){
						tmp.PB(v[k]);
					}
				}
				if(tmp.size()<=2){
					continue;
				}
				vector<P> tt=convex_hull(tmp);
				sort(ALL(tt));
				auto it=lower_bound(ALL(tt),v[i]);
				P t1=*it;
				if(t1.real()==v[i].real()&&t1.imag()==v[i].imag()){
					// cout<<"a "<<j<<endl;
					ans=min(ans,n-__builtin_popcount(j));
				}
				if(j==1) break;
			}
			cout<<ans<<endl;
		}
	}
}


main() {
    mainmain();
}