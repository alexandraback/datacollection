// tsukasa_diary's programing contest code template
#include <bits/stdc++.h>
using namespace std;
#define TSUKASA_DIARY_S_TEMPLATE
// define
#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define for_rev(i,a,b) for(int i=(a);i>=(b);--i)
#define allof(a) (a).begin(),(a).end()
#define minit(a,b) memset(a,b,sizeof(a))
#define size_of(a) int((a).size())
#define cauto const auto
// typedef
typedef long long lint;
typedef double Double;
typedef pair< int, int > pii;
template< typename T > using Vec = vector< T >;
template< typename T > using Matrix = Vec< Vec< T > >;
template< typename T > using USet = unordered_set< T >;
template< typename T, class C > using MyUSet = unordered_set< T, C >;
template< typename T, typename F > using UMap = unordered_map< T, F >;
template< typename T, typename F, class C > using MyUMap = unordered_map< T, F, C >;
// hash
class PiiHash { public: size_t operator () (const pii& p) const { return (p.first << 16) | p.second; } };
// popcount
inline int POPCNT(int x) { return __builtin_popcount(x); }
inline int POPCNT(lint x) { return __builtin_popcount(x); }
// inf
const int iINF = 1L << 30;
const lint lINF = 1LL << 60;
// eps
const Double EPS = 1e-9;
const Double PI = acos(-1);
// inrange
template< typename T >
inline bool in_range(T v, T mi, T mx) { return mi <= v && v < mx; }
template< typename T >
inline bool in_range(T x, T y, T W, T H) { return in_range(x,0,W) && in_range(y,0,H); }
// neighbor clockwise
const int DX[4] = {0,1,0,-1}, DY[4] = {-1,0,1,0};
const int DX_[8] = {0,1,1,1,0,-1,-1,-1}, DY_[8] = {-1,-1,0,1,1,1,0,-1};
// variable update
template< typename T > inline void modAdd(T& a, T b, T mod) { a = (a + b) % mod; }
template< typename T > inline void minUpdate(T& a, T b) { a = min(a, b); }
template< typename T > inline void maxUpdate(T& a, T b) { a = max(a, b); }
// converter
template< typename F, typename T >
inline void convert(F& from, T& to) {
	stringstream ss;
	ss << from; ss >> to;
}

int N, P[30];
bool f[30];

void solve() {
	cin >> N;
	for_(i,0,N) cin >> P[i];
	
	int sum = accumulate(P, P + N, int());
	
	priority_queue< pii > que;
	
	for_(i,0,N) {
		que.push(pii(P[i], i));
		if ((sum + 1) / 2 <= P[i]) f[i] = true;
		else f[i] = false;
	}
	
	vector< string > ans;
	
	while (!que.empty()) {
		pii p1 = que.top(); que.pop();
		
		if (p1.first == 0) break;
		
		if (que.empty()) {
			string add = "";
			add += char('A' + p1.second);
			ans.push_back(add);
			continue;
		}
		
		pii p2 = que.top();
		
		if (p2.first != 0 && f[p2.second]) {
			que.pop();
			que.push(pii(p1.first - 1, p1.second)); P[p1.second]--;
			que.push(pii(p2.first - 1, p2.second)); P[p2.second]--;
			
			string add = "";
			add += char('A' + p1.second);
			add += char('A' + p2.second);
			ans.push_back(add);
			
			sum -= 2;
			
			for_(i,0,N) {
				if ((sum + 1) / 2 <= P[i]) f[i] = true;
				else f[i] = false;
			}
		} else {
			que.push(pii(p1.first - 1, p1.second)); P[p1.second]--;
			
			string add = "";
			add += char('A' + p1.second);
			ans.push_back(add);
			
			sum -= 1;
			
			for_(i,0,N) {
				if ((sum + 1) / 2 <= P[i]) f[i] = true;
				else f[i] = false;
			}
		}
	}
	
	int m = ans.size();
	for_(i,0,m) cout << ans[i] << (i < m - 1 ? " " : "\n");
}

int main() {
	int T;
	cin >> T;
	
	for_(i,0,T) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
