#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		int N;
		scanf("%d", &N);
		vector<int> m(N);
		rep(i, N) scanf("%d", &m[i]);
		int ans1 = 0;
		rep(i, N-1) ans1 += max(0, m[i] - m[i+1]);
		int ans2 = INF;
		rer(a, 0, 10000) {
			bool ok = true;
			int x = 0;
			rep(i, N-1) {
				ok &= max(0, m[i] - a) <= m[i+1];
				x += min(a, m[i]);
			}
			if(ok)
				amin(ans2, x);
		}
		printf("Case #%d: %d %d\n", ii+1, ans1, ans2);
	}
	return 0;
}
