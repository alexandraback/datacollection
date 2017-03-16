#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
#include <iomanip>
#include <cstring>
#include <unistd.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, b;
ll n;
int m[10000];

ll pos(ll t){
	ll ans = 1;
	REP(i, b){
		ans += (t/m[i] + (t%m[i] != 0));
	}
	return ans;
}

int av(ll t){
	ll p = pos(t);
	REP(i, b){
		if(t%m[i] == 0){
			if(p == n) return (i+1);
			else p++;
		}
	}
	return -1;
}

int main(){
	cin >> t; 
	REPP(tc, 1, t+1){
		cin >> b >> n;
		REP(i, b) cin >> m[i];
		ll hi = 1000000000000000, lo = -1, mid, ans = -1;
		while(hi-lo>1){
			mid = (hi+lo)/2LL;
			ll p = pos(mid);
			//cout << " TEMPO " << mid << " POS " << p << " N " << n << endl;
			if(p < n){
				ans = mid;
				lo = mid;
			}
			else if(p > n) hi = mid;
			else{
				ans = mid;
				break;
			}
		}
		//cout << " ans " << ans << endl;
		int ANS;
		while((ANS = av(ans)) == -1){
			//cout << " ANS " << ANS << endl;
			ans++;
		}
		//cout << "ANS TEMPO " << ans << endl;
		cout << "Case #" << tc << ": " << ANS << endl;
		
	}
}
