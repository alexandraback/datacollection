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
static const int INF=1<<24;
void mainmain(){
	int T;
	cin>>T;
	rep(o,T){
		cout<<"Case #"<<o+1<<": ";
		ll n,b;
		cin>>n>>b;
		vll v(n);
		rep(i,n){
			cin>>v[i];
		}
		ll l=0,r=n*b+10000;
		while(1){
			// cout<<l<<" "<<r<<endl;
			if(l==r) break;
			ll pi=(l+r+1)/2;
			ll t1=0;
			rep(i,n){
				t1+=pi/v[i];
				t1++;
			}
			ll t2=0;
			rep(i,n){
				t2+=(pi-1)/v[i];
				t2++;
			}
			// cout<<"t1 t2 "<<t1<<" "<<t2<<endl;
			if(t1>=b&&t2<b){
				l=r=pi;
				break;
			}
			if(t1>=b){
				r=pi-1;
			}
			else{
				l=pi;
			}
		}
		ll ans=-1;
		if(l==0){
			cout<<b<<endl;
			continue;
		}
		ll t=0;
		rep(i,n){
			t+=(l-1)/v[i];
			t++;
		}
		b-=t;
		// cout<<"b "<<b<<endl;
		rep(i,n){
			if(l%v[i]==0){
				b--;
			}
			if(b==0){
				ans=i+1;
				break;
			}
		}
		cout<<ans<<endl;
	}
}


main() {
    mainmain();
}