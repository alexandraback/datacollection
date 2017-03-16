#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long        LL;
typedef pair<int, int>   pii;
typedef pair<int, pii>   piii;
typedef vector<int>      vi;
typedef vector<pii>      vii;
typedef vector<piii>     viii;

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
inline void inpint( int &n ) {
  n=0; register int ch = getchar_unlocked(); bool sign = 0;
  while(ch < 48 || ch > 57) { if(ch == '-') sign = 1; ch = getchar_unlocked(); }
  while(ch >= 48 && ch <= 57) { n = (n << 3) + (n << 1) + ch - 48, ch = getchar_unlocked(); }
  if(sign) n = -n;
}

inline int sqr(int x){return x * x;}
inline int cube(int x){return x * x * x;}
inline LL sqrLL(LL x){return x * x;}
inline LL cubeLL(LL x){return x * x * x;}

const LL LLINF      = 9223372036854775807LL;
const LL LLINF17    = 100000000000000000LL;
const int INF       = 2147483647;
const int INF9      = 1000000000;
const int MOD       = 1000000007;
const double eps    = 1e-7;
const double PI     = acos(-1.0);

#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

#define RESET(a,b)   memset(a,b,sizeof(a)) 
#define SYNC         ios_base::sync_with_stdio(0);
#define SIZE(a)      (int)(a.size())
#define MIN(a,b)     (a) = min((a),(b))
#define MAX(a,b)     (a) = max((a),(b))
#define ALL(a)       a.begin(),a.end()
#define RALL(a)      a.rbegin(),a.rend()
#define SIZE(a)      (int)(a.size())
#define LEN(a)       (int)(a.length())

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair

int dr[] = {1,0,-1,0,-1,1,1,-1};
int dc[] = {0,-1,0,1,1,1,-1,-1};
int t, n, arr[1005];
int main(){
	scanf("%d",&t);
	REPN(tc,t){
		printf("Case #%d: ",tc);
		scanf("%d",&n);
		REPN(i,n) scanf("%d",&arr[i]);

		int ans1 = 0, rate = INF9;
		int ans2 = 0;
		FORN(i,2,n) {
			if (arr[i-1] > arr[i]) ans1 += (arr[i-1] - arr[i]);
		}

		int lo = 0, hi = 10000, mid;
		while (lo <= hi) {
			mid = (lo + hi) >> 1;
			bool possible = 1;

			FORN(i,2,n) {
				if (arr[i-1] - mid > arr[i]) {
					possible = 0;
					break;
				}
			}

			if (possible) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		REPN(i,n-1) {
			ans2 += min(lo, arr[i]);
		}

		printf("%d %d\n",ans1,ans2);
	}

	return 0;
}