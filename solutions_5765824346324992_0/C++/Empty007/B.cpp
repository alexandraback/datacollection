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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

typedef long long ll;

ll A[1010];

int main() {
    int T, B;
    ll N;
    cin >> T;
    REP(tc, T) {
		cin >> B >> N;
		REP(i, B) cin >> A[i];
		
		if (N <= B) {
			printf("Case #%d: %lld\n", tc+1, N);
			continue;
		}
		
		ll l = 0, h = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
		
		while (l + 1 < h) {
			ll mid = (l + h)/2;
			ll cnt = 0;
			REP(i, B) {
				cnt += ((mid+A[i]-1)/A[i]);
			}
			if (cnt >= N) h = mid;
			else l = mid;
		}
		
		ll cnt = 0;
		REP(i, B) {
			cnt += (h-1+A[i]-1)/A[i];
		}
		
		int res = 0, first = -1;
		//dbg2(h, cnt);
		REP(i, B) {
			if ((h-1) % A[i] == 0) {
				cnt++;
				if (first == -1) first = i+1;
			}
			if (cnt == N) {
				res = i+1;
				break;
			}
		}
		if (res == 0) res = first;
        printf("Case #%d: %d\n", tc+1, res);
    }	
    return 0;
}

