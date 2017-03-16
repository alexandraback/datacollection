
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

ll m[10000];

int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1){
		ll N;
		int B;
		cin >> B >> N;
		FOR(i,0,B)cin >> m[i];
		ll lo = 0, hi = 100000LL * 1000000000LL * 10;
		while(lo < hi){
			ll mid = lo + (hi - lo)/ 2;
			ll done = B;
			FOR(i,0,B){
				done += mid / m[i];
				if(done > N)break;
			}
			if(done >= N)hi = mid;
			else lo = mid + 1;
		}
		ll done = B;
		FOR(i,0,B)done += lo / m[i];
		int res = -1;
		FORD(i,0,B)if(lo % m[i] == 0){
			if(done-- == N)res = i + 1;
		}
		cout << "Case #" << tc << ": " << res << endl;
	}
	return 0;
}
