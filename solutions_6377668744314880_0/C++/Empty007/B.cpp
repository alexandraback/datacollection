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

int cross(pair < int, int > a, pair < int, int > b, pair < int, int > c) { // c punto fuera, a punto inicial //imagino que es para ver si c esta a la izquierda de la linea a->b
	return (b.first - a.first)*(c.second - a.second) - (b.second - a.second)*(c.first - a.first);
}

void convex_hull(vector < pair <int, int > > &H, vector < pair <int, int > > &v) {

    int k = 0, n = v.size();

    sort(ALL(v));
    
    REP(i, n) {
        while (k >= 2 && cross(H[k-2], H[k-1], v[i]) < 0) k--;
        H[k++] = v[i];
    }
    
    for (int i = n - 2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], v[i]) < 0) k--;
        H[k++] = v[i];
    }
    
    H.resize(k);
}

int main() {
    int T, n, x, y;
    cin >> T;
    REP(tc, T) {
		cin >> n;
		vector < pair <int, int > > pol1;
		REP(i, n) {
			cin >> x >> y;
			pol1.pb(mp(x, y));
		}
		
		printf("Case #%d:\n", tc+1);
		
		
		vector < pair < int, int > > pol2;
	
		REP(i, n) {
			int res = 0;
			REP(j, (1<<n)) if ((1<<i) & j) {
				pol2.clear();
				REP(k, n) if ((1<<k) & j) {
					pol2.pb(pol1[k]);
				}
				vector < pair < int, int > > H1(n+20, mp(0, 0));	
				convex_hull(H1, pol2);
				bool bo = false;
				REP(k, H1.size()) {
					if (H1[k] == pol1[i]) bo = true;
				}
				if (bo) res = max(res, int(__builtin_popcount(j)));
			}
			printf("%d\n", n-res);
		}
    }	
    return 0;
}
	
