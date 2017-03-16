#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef pair<LL, LL>    PLL;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
typedef vector<PLL>     VPLL;
#define MM(a,x) memset(a,x,sizeof(a));
#define ALL(x)  (x).begin(), (x).end()
#define P(x)	cerr<<"["#x<<" = "<<(x)<<"]\n"
#define PP(x,i)	cerr<<"["#x<<i<<" = "<<x[i]<<"]\n"
#define P2(x,y)	cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<"]\n"
#define TM(a,b)	cerr<<"["#a" -> "#b": "<<1e3*(b-a)/CLOCKS_PER_SEC<<"ms]\n";
#define UN(v) sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0);}} _;
template<class T> void PV(T a, T b) {while(a != b)cout << *a++, cout << (a != b ? " " : "\n");}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template<class T> string tostring(T x, int len = 0) {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), '0') + r; return r;}
template<class T> void convert(string x, T& r) {stringstream ss(x); ss >> r;}
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 111111;

int main() {
	int T;
	int r1, r2, t;	
	cin >> T;
	for(int ts = 1; ts <= T; ts++) {
		cin >> r1;
		vector<int> v1, v2, v3;
		for(int i = 1; i <= 4; i++) 
			for(int j = 1; j <= 4; j++) {
				cin >> t;
				if(i == r1) v1.pb(t);
			}

		cin >> r2;
		for(int i = 1; i <= 4; i++) 
			for(int j = 1; j <= 4; j++) {
				cin >> t;
				if(i == r2) v2.pb(t);
			}
		for(auto i : v1) if(find(ALL(v2), i) != v2.end()) v3.pb(i);
		cout << "Case #" << ts << ": ";
		if(v3.size() == 0) cout << "Volunteer cheated!" << endl;
		else if(v3.size() == 1) cout << v3[0] << endl;
		else cout << "Bad magician!" << endl;
	}
	return 0;
}
