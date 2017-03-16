#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;

#define maxB 1000
#define maxN 1000000000LL
#define maxM 100000LL

ll T, caso = 1, B, N, barbers[maxB];
pll sortBarb[maxB];

pll solve(ll mid) {
	ll ret = 0;
	ll ret2 = 0;
	FOR(i, 0, B) {
		ret += mid / barbers[i];
		ll t = mid%barbers[i];
		if (t) ret++;
		else ret2++;
	}
	return pll(ret, ret+ret2);
}

bool comp(pll &l, pll &r) {
	return l.first < r.first || (l.first==r.first&&l.second<r.second);
}

int main() {
	ll ans;
	cin >> T;
	while (T--) {
		cin >> B >> N;
		FOR(i, 0, B) {
			cin >> barbers[i];
		}
		ll lo = 0, hi = maxN*maxM; //hi is 10 pow 14
		//hi = 100;
		while (lo + 1 < hi) {
			ll mid = (lo + hi)>>1;
			pll s = solve(mid);
			if (s.first>=N) {
				hi = mid - 1;
			}
			else {
				if (s.second<N) lo = mid+1;
				if (s.second >= N) hi = mid;
			}
		}
		pll s = solve(hi);
		ll pos;
		if (s.first<N) {
			ans = hi;
		}
		else {
			s = solve(lo);
			ans = lo;
		}
		pos = N - s.first - 1;
		FOR(i, 0, B) {
			sortBarb[i].first = (barbers[i]-ans%barbers[i])%barbers[i];
			//if (!sortBarb[i].first) sortBarb[i].first = INF;
			sortBarb[i].second = i+1;
		}
		sort(sortBarb, sortBarb + B, comp);
		cout << "Case #" << caso++ << ": " << sortBarb[pos].second << endl;
	}
	return 0;
}
