#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#endif

using namespace std;


namespace{

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

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


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
//#define EPS 1e-8


typedef long double D;
typedef complex<D> P;
typedef pair<D,int> pdi;

const D pi = acos(D(-1));
const D EPS = 1.14514e-10;

void prepare(){
	
}


vint solve(){
	P rt = polar(D(1), D(EPS));

	int n;
	cin >> n;
	vector<P> ps(n);
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		ps[i] = P(x, y) * rt;
	}
	
	vint ans(n, -1);
	vector<pdi> v;
	v.reserve(4 * n + 10);
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		v.clear();

		for(int j = 0; j < n; ++j){
			if(i == j){ continue; }
			D a = arg(ps[j] - ps[i]);
			if(a >= 0){
				++cnt;
				v.emplace_back(a, -1);
				v.emplace_back(a + pi, 1);
				v.emplace_back(a + 2 * pi, -1);
				v.emplace_back(a + 3 * pi, 1);
			}
			else{
				v.emplace_back(a + pi, 1);
				v.emplace_back(a + 2 * pi, -1);
				v.emplace_back(a + 3 * pi, 1);
				v.emplace_back(a + 4 * pi, -1);
			}
		}
		sort(ALL(v), [](const pdi &a, const pdi &b){
			return abs(a.first - b.first) > EPS ? a.first < b.first : a.second < b.second;
		});
		int res = cnt;
		for(cauto p : v){
			cnt += p.second;
			res = min(res, cnt);
		}
		
		ans[i] = res;
	}
	return ans;
}


}
int main(){
	cout << fixed << setprecision(15);
	cerr << fixed << setprecision(15);
	prepare();

	int T = 0;
	cin >> T;
	for(int cnum = 1; cnum <= T; ++cnum){
		fprintf(stderr, "%4d / %d\n", cnum, T);
		auto ans = solve();
		cout << "Case #" << cnum << ":\n";
		for(int x : ans){ cout << x << '\n'; }
		cout << flush;
	}
}
