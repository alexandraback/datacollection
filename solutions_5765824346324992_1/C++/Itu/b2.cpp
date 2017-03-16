#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb(x) push_back(x)
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define trace(x) cerr << #x << ": " << x << endl;
#define fst first
#define snd second
#define itm1 fst.fst
#define itm2 fst.snd
#define itm3 snd
#define mt(a,b,c) mp(mp(a,b),c)
typedef pair<long long, long long> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int64;
typedef unsigned long long uint64;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ii, int> tri;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> tri64;
typedef set<int> seti;
typedef set<ii> setii;
typedef stack<int> stki;
typedef stack<ii> stkii;
typedef queue<int> qi;
typedef queue<ii> qii;
typedef map<int,int> mapii;
typedef map<string,int> mapsi;
typedef unsigned int uint;

const double PI = 3.14159265359;

ll b, n;
tri m[2000];
ll ans;
ll x, y, z;
priority_queue<tri, vector<tri >, greater<tri > > pq;
vector<tri> v;
tri curr, nxt;

const ll MULTIP = 1000;

// (rem, pos, m)

ll min(ll x1, ll x2){
	if (x1 < x2) return x1;
	return x2;
}

int min(int x1, int x2){
	if (x1 < x2) return x1;
	return x2;
}

int main(){
	int nCases;
	cin >> nCases;
	REP(casenum,0,nCases){
		pq = priority_queue<tri, vector<tri >, greater<tri > >();
		v.clear();
		cin >> b >> n;
		REP(i,0,b){
			cin >> x;
			m[i] = mt(x, i+1, x);
		}
		if (n <= b){
			cout << "Case #" << casenum+1 << ": " << n << endl;
			continue;
		}
		if (b == 1){
			cout << "Case #" << casenum+1 << ": " << 1 << endl;
			continue;
		}
		n -= b;
		ans = 0;
		if (n > 1000000){
			REP(i,0,b){
				pq.push(mt(m[i].itm1, m[i].itm2, m[i].itm3*MULTIP));
			}
//			cout << "Starting n reduction" << endl;
			while (n > 0){
				curr = pq.top();
				pq.pop();
				n -= MULTIP;
				pq.push(mt(curr.itm1 + curr.itm3, curr.itm2, curr.itm3));
			}
//			cout << "Finish n reduction with n =" << n << endl;
			while(!pq.empty()){
				curr = pq.top();
				pq.pop();
				v.pb(mt(curr.itm1, curr.itm2, curr.itm3/MULTIP));
			}
			ll mintm = 2000000000000000000LL;
			REP(i,0,v.size()){
				mintm = min(mintm, v[i].itm1);
//				cout << "element: (" << v[i].itm1 << "," << v[i].itm2 << "," << v[i].itm3 << ")" << endl;
			}
//			cout << "mintm found at: " << mintm << endl;
			REP(i,0,v.size()){
				ll dif = (v[i].itm1 - mintm) / v[i].itm3;
				if (dif > 0){
					n += dif;
					v[i].itm1 -= v[i].itm3*dif;
				}
			}
//			cout << "n augmented: n = " << n << endl;
			if (n < 0){
				ll mul = (-n/b + 1);
				n += b*mul;
				REP(i,0,v.size()){
					v[i].itm1 -= v[i].itm3*mul;
				}
			}
			if (n == 0){
				ans = 0;
				mintm = 2000000000000000000LL;
				REP(i,0,v.size()){
					if (mintm >= v[i].itm1 - v[i].itm3){
						ans = min(ans, v[i].itm2);
						mintm = v[i].itm1 - v[i].itm3;
					}
				}
				cout << "Case #" << casenum+1 <<	": " << ans << endl;
				continue;
			}
			REP(i,0,v.size()){
				pq.push(v[i]);
			}
		}
		else{
			REP(i,0,b){
				pq.push(m[i]);
			}
		}
		while (!ans){
			while (!ans && !pq.empty()){
				curr = pq.top();
				pq.pop();
				n--;
				if (n == 0){
					ans = curr.itm2;
					break;
				}
				else{
					pq.push(mt(curr.itm1 + curr.itm3, curr.itm2, curr.itm3));
				}
			}
			if (ans) break;
		}
		cout << "Case #" << casenum+1 << ": " << ans << endl;
	}  
	return 0;
}

